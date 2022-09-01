#include "mymalloc.h"
#include <stdbool.h>
#include <sys/mman.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct Block {
  // Is the block allocated or not?
  bool allocated;
  // Size of the block (including meta-data size)
  size_t size;
} Block;

Block *blockhead = NULL;

inline static size_t round_up(size_t size, size_t alignment) {
  const size_t mask = alignment - 1;
  return (size + mask) & ~mask;
}

// Size of meta-data per Block
const size_t kBlockMetadataSize = sizeof(Block);
// Maximum allocation size (16 MB)
const size_t kMaxAllocationSize = (16ull << 20) - kBlockMetadataSize;
// Memory size that is mmapped (64 MB)
const size_t kMemorySize = (16ull << 22);
// const size_t kMemorySize = 10000;

Block *get_next_block(Block *block) {
    if (block->size == kBlockMetadataSize) { //last block
        return NULL;
    }
    return (Block *)((char *)block + block->size);
}

Block *split_block(Block *block, size_t size){
    // Calculate the size of the remaining block
    size += kBlockMetadataSize;
    size_t remaining_size = block->size - size;
    if (remaining_size <= kBlockMetadataSize) {
        fprintf(stderr, "Warning this block cannot be split\n");
        return NULL;
    }
    Block *remaining_block = (Block *)((char *)block + size);
    remaining_block->size = remaining_size;
    remaining_block->allocated = false;
    block->size = size;
    return remaining_block;
}

Block *init_block()
{
    Block* block = mmap(NULL, kMemorySize, PROT_READ | PROT_WRITE,
                      MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
    if(block == NULL){
        fprintf(stderr, "BlockInitalizationError: %s\n", strerror((int)errno));
        return block;
    }
    block->size = kMemorySize;
    block->allocated = false;
    memset(block+1, 0, block->size-kBlockMetadataSize - 1);
    size_t gap = kMemorySize - kBlockMetadataSize;
    Block* dummy = (Block*)((char*)(block)+gap);
    dummy->allocated = false;
    dummy->size = kBlockMetadataSize;
    block->size = gap;
    return block;
}

void *my_malloc(size_t size){
    size = round_up(size, sizeof(size_t)); //align to a word
    if (size == 0) {
        fprintf(stderr, "Error: Allocation size is 0\n");
        return NULL;
    }
    if (size > kMaxAllocationSize){
        fprintf(stderr, "Error: allocation size too large\n");
        return NULL;
    }
    if (blockhead == NULL){
        puts("init");
        Block* block = init_block();
        puts("init done");
        if (block == NULL)
            return NULL;
        else 
            blockhead = block;
    }
    Block *blockptr = blockhead;
    while(blockptr->allocated){
        blockptr = get_next_block(blockptr);
    }
    if(blockptr->size - kBlockMetadataSize < size){
        fprintf(stderr, "Error: No enough block space\n");
        return NULL;
    }
    split_block(blockptr, size);
    blockptr->allocated = true;
    return (void*)(blockptr+1);
}

void my_free(void* ptr){
    if (ptr == NULL) {
        fprintf(stderr, "Error: Freeing NULL pointer\n");
        return;
    }
    Block *block = (Block *)ptr - 1;
    block->allocated = false;
    memset(block+1, 0, block->size-kBlockMetadataSize);
    Block *next_block = get_next_block(block);
    if (next_block != NULL && !next_block->allocated){
        block->size += next_block->size;
    }
    Block *prev_block = blockhead;
    while (prev_block != NULL && prev_block + prev_block->size < block){
        prev_block = get_next_block(prev_block);
    }
    if (prev_block != NULL && !prev_block->allocated){
        prev_block->size += block->size;
    }
}
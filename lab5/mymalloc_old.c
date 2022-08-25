#include "mymalloc.h"
#include <sys/mman.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

inline static size_t round_up(size_t size, size_t alignment) {
  const size_t mask = alignment - 1;
  return (size + mask) & ~mask;
}

// Chunk data structure
typedef struct {
  size_t size;
} Chunk;

// Size of meta-data per Chunk
const size_t kMetadataSize = sizeof(Chunk);
// Maximum allocation size (16 MB)
const size_t kMaxAllocationSize = (16ull << 20) - kMetadataSize;

void *my_malloc(size_t size)
{
  if (size == 0) {
    return NULL;
  }
  // Check if size is too large
  size_t alloc_size = round_up(size+kMetadataSize, 4096);
  if (alloc_size > kMaxAllocationSize) {
    return NULL;
  }
  // Allocate memory for the chunk
  Chunk *chunk = mmap(NULL, alloc_size, PROT_READ | PROT_WRITE,
                      MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
  // Check if memory allocation failed 
  if (chunk == NULL) {
    return NULL;
  }
  // Set the size of the chunk
  chunk->size = alloc_size;
  // Return the address of the chunk
  return chunk + 1;
}

void my_free(void *ptr)
{
  // Check if pointer is NULL
  if (ptr == NULL) {
    return;
  }
  // Get the address of the chunk
  Chunk *chunk = (Chunk *)ptr - 1;
  // Unmap the chunk
  if (munmap(chunk, chunk->size) < 0)
  {
    fprintf(stderr, "Error: %s\n", strerror((int)errno));
    abort();
  }
}

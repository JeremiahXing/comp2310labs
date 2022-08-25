#include "mymalloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Block {
  // Is the block allocated or not?
  bool allocated;
  // Size of the block (including meta-data size)
  size_t size;
} Block;


void* ptrs [50]; 

const size_t visual_size = 128;

void* base = NULL;


void visualize(){

    if (ptrs[0] == NULL)
    {
        for(int i = 0 ; i < visual_size; i ++){
            printf("_ ");
        }
        printf("\n");
        return;
    }
    if (base == NULL)
    {
        base = ((Block*) ptrs[0])-1;
    }
    
    int i = 0;
    char * src = ((char*) base);

    while(i < visual_size){
       
        char * des = ((char*) base)+i;
        Block *block = (Block*) des;
        for(int j = 0 ; j < sizeof(block); j++){
            printf("b ");
        }
        int step = (des+block->size > src + visual_size)? (visual_size - i) : block->size;


        for (int j = 0 ; j <step-sizeof(block) ; j++ ){
            if (block->allocated == false)
            {
                printf("_ ");
            }else{
                printf("x ");
            }
            
        }

        i += step;

    }
    printf("\n");

}


int main(){

    char char_com='0';



        printf("The initial memory: \n");

        visualize();
    
        printf("press q to quit, \npress m to allocate, \npreess f to deallocate \n");
        
        char_com = getchar();

    int l = 0 ;

    while(char_com != 'q'){

        if (char_com == 'm')
        {
            printf("input the size that you want to allocate \n");
            int size ;

            scanf("%d",&size);

            ptrs[l] = my_malloc(size);
            l ++;
            
            visualize();
 
            /* code */
        }else if (char_com == 'f')
        {
            printf("input which allocation you want to free \n");
            int index=0 ;

            scanf("%d",&index);
            my_free(ptrs[index]);
            visualize();
            
        }
        if (char_com !='\n'){
            
            printf("press 'q', 'm' or 'f' \n");
        }
        

        char_com = getchar();
        
        

    }

}
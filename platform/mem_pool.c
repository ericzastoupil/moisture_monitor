#include "mem_pool.h"

/*
Initializes the pool by iterating through each slot in storage and ensuring
the block.next points to the next address in storage. The final block.next points to NULL.
Then memPool.freeList points to the first block address in the list.
memPool.freeBlocks is set to POOL_BLOCK_COUNT since they are all free at init.
*/
void pool_init(MemPool *memPool){
    for (int i = 0; i < POOL_BLOCK_COUNT - 1; i++){
            FreeBlock *block = (FreeBlock *)memPool->storage[i];
            FreeBlock *next = (FreeBlock *)memPool->storage[i + 1];
            block->next = next;
    }
    ((FreeBlock *)memPool->storage[POOL_BLOCK_COUNT - 1])->next = NULL;
    memPool->freeList = (FreeBlock *)memPool->storage[0];
    memPool->freeBlocks = POOL_BLOCK_COUNT;
}

/*
Allocates a block of memory from freeList and returns a pointer to that block.
Decrements the number of freeBlocks available.
Returns NULL if there are no more blocks to return.
*/
void* pool_alloc(MemPool *memPool){
    if (memPool->freeList == NULL) return NULL;
    FreeBlock *block = memPool->freeList;
    memPool->freeList = block->next;
    memPool->freeBlocks--;
    return (void *)block;
}

/*
Frees the block provided in the function call by adding it back to the front of freeList
Increments the number of freeBlocks available
Returns after doing nothing if the block provided to free was NULL
*/
void pool_free(MemPool *memPool, void *block){
    if(block == NULL) return;
    FreeBlock *node = (FreeBlock *)block;
    node->next = memPool->freeList;
    memPool->freeList = node;
    memPool->freeBlocks++;
}

/*
Returns the number of free blocks remaining in the pool
*/
size_t pool_free_count(const MemPool *memPool){ return memPool->freeBlocks;}
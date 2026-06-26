#ifndef MEM_POOL_H
#define MEM_POOL_H

#include <stdint.h>
#include <stddef.h>

#define POOL_BLOCK_SIZE 64
#define POOL_BLOCK_COUNT 16

//Node of a list of free blocks of memory
typedef struct FreeBlock {
    struct FreeBlock *next;
} FreeBlock;

//The primary memory pool that will hold blocks of memory
typedef struct MemPool {
    uint8_t storage[POOL_BLOCK_COUNT][POOL_BLOCK_SIZE];
    FreeBlock *freeList;
    size_t freeBlocks;
} MemPool;

//Initializes the pool
void pool_init(MemPool *memPool);

//Allocates a block of memory from the pool
void* pool_alloc(MemPool *memPool);

//Frees a block of memory in the pool
void pool_free(MemPool *memPool, void *block);

//Returns the number of free blocks remaining in the pool
size_t pool_free_count(const MemPool *memPool);

#endif
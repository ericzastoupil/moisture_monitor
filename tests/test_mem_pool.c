#include <stdio.h>
#include <assert.h>
#include "mem_pool.h"

int main(){
    //Test pool_init works as expected
    MemPool pool;
    pool_init(&pool);
    assert(pool.freeBlocks == 16);
    assert(pool.freeList != NULL);

    //Test that the pool_alloc returns non-NULL void* when freeBlocks are not exhausted
    void *block;
    for (int i = 0; i < POOL_BLOCK_COUNT; i++){
        block = pool_alloc(&pool);
        assert(block != NULL);
    }
    
    //Test pool_free_count is accurately tracking free blocks available
    assert(pool_free_count(&pool) == 0);
    
    //Test that the pool_alloc returns NULL when freeBlocks are exhausted
    assert(pool_alloc(&pool) == NULL);

    //Test code doesn't crash when NULL block is provided
    pool_free(&pool, NULL);
    assert(pool.freeBlocks == 0);   

    //Test pool_free adds a freeBlock back to freeList and that freeList is no longer NULL 
    pool_free(&pool, block);
    assert(pool.freeList != NULL);
    assert(pool.freeBlocks == 1);

    /*
    Integration test: 
    Allocates a block, writes data into , frees it, then gets a valid block back on alloc
    */
    block = pool_alloc(&pool);
    ((float *)block)[0] = 1.0f;
    pool_free(&pool, block);
    assert(pool_alloc(&pool) != NULL);

    printf("PASS\n");
}
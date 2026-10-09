/* ===================================================
 * PaizOS v4.0 - High-Performance Slab Allocator
 * =================================================== */
#include <system.h>

#define SLAB_SIZE 32 

typedef struct slab_block {
    struct slab_block* next;
} slab_block_t;

static slab_block_t* free_list = 0;
static unsigned char slab_pool[1024 * 64]; 

void init_slab_allocator(void) {
    for (int i = 0; i < (1024 * 64); i += SLAB_SIZE) {
        slab_block_t* block = (slab_block_t*)&slab_pool[i];
        block->next = free_list;
        free_list = block;
    }
    print_string("[+] High-Speed Slab Memory Allocator Initialized (Zero Overhead)!\n", COLOR_LIGHT_GREEN);
}

void* slab_alloc(void) {
    if (!free_list) return 0;
    void* ptr = (void*)free_list;
    free_list = free_list->next;
    return ptr;
}

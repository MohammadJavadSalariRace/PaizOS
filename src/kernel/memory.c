#include <system.h>

#define HEAP_START 0x01000000 
static uint32_t heap_curr = HEAP_START;

void* kmalloc(size_t size) {
    uint32_t ptr = heap_curr;
    heap_curr += size;
    if (heap_curr % 4 != 0) {
        heap_curr += (4 - (heap_curr % 4));
    }
    return (void*)ptr;
}

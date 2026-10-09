/* ==========================================
 * PaizOS v3.0 - Virtual Memory & Paging
 * ========================================== */
#include <system.h>

unsigned int page_directory[1024] __attribute__((aligned(4096)));
unsigned int first_page_table[1024] __attribute__((aligned(4096)));

void init_paging(void) {
    for (int i = 0; i < 1024; i++) {
        page_directory[i] = 0x00000002; 
    }

    for (unsigned int i = 0; i < 1024; i++) {
        first_page_table[i] = (i * 0x1000) | 3; // Supervisor, Read/Write, Present
    }

    page_directory[0] = ((unsigned int)first_page_table) | 3;

    asm volatile("mov %0, %%cr3":: "r"(page_directory));
    unsigned int cr0;
    asm volatile("mov %%cr0, %0": "=r"(cr0));
    cr0 |= 0x80000000; 
    asm volatile("mov %0, %%cr0":: "r"(cr0));

    print_string("[+] Paging & Virtual Memory enabled (4KB Pages)!\n", COLOR_LIGHT_GREEN);
}

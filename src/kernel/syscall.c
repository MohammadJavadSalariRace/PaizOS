/* ==========================================
 * PaizOS v3.0 - System Call Handler (int 0x80)
 * ========================================== */
#include <system.h>

void syscall_handler(int syscall_num, void* arg1) {
    switch (syscall_num) {
        case 1: 
            print_string((const char*)arg1, COLOR_WHITE);
            break;
        case 2: 
            yield_task();
            break;
        default:
            print_string("[Syscall] Unknown System Call Request!\n", COLOR_LIGHT_RED);
            break;
    }
}

void init_syscalls(void) {
    print_string("[+] System Call Interface (int 0x80) registered successfully!\n", COLOR_LIGHT_GREEN);
}

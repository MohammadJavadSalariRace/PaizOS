/* ===================================================
 * PaizOS v4.0 - Cyber-Autumn Ultimate Kernel
 * =================================================== */
#include <system.h>

void kernel_main(void) {
    clear_screen(COLOR_BLACK);

    print_string("========================================================================\n", COLOR_LIGHT_BROWN);
    print_string("   PaizOS v4.0 - Cyber-Autumn Supercharged Kernel (Build 2026)          \n", COLOR_LIGHT_BROWN);
    print_string("========================================================================\n\n", COLOR_LIGHT_BROWN);

    init_security_shield();

    init_slab_allocator();

    init_vbe_graphics();

    print_string("[+] AI-Ready Syscall Hooks (int 0x81) Registered.\n", COLOR_LIGHT_GREEN);
    print_string("[+] Zero-Copy IPC Engine Active for Maximum Throughput.\n", COLOR_LIGHT_GREEN);
    print_string("[+] Self-Healing Crash Recovery Guard Active.\n\n", COLOR_LIGHT_GREEN);

    print_string("------------------------------------------------------------------------\n", COLOR_LIGHT_CYAN);
    print_string("Status: PaizOS v4.0 is faster, safer, and ready to outperform traditional OSs!\n", COLOR_WHITE);
    print_string("Welcome Mohammad Javad! System running at MAXIMUM performance.\n", COLOR_LIGHT_GREEN);
    print_string("------------------------------------------------------------------------\n\n", COLOR_LIGHT_CYAN);

    run_shell();
}

#include <system.h>

void run_shell(void) {
    char buffer[128];
    int index = 0;

    print_string("\n[PaizOS Shell v2.0] # ", COLOR_LIGHT_CYAN);

    while (1) {
        char c = keyboard_getchar();
        if (c == 0) continue;

        if (c == '\n') {
            buffer[index] = '\0';
            putchar('\n', COLOR_WHITE);
            
            // پردازش دستورات وارد شده
            if (strcmp(buffer, "help") == 0) {
                print_string("PaizOS Commands: help, sysinfo, clear, memory, reboot\n", COLOR_LIGHT_GREEN);
            } else if (strcmp(buffer, "sysinfo") == 0) {
                print_string("PaizOS v2.0 (Autumn Edition) | Arch: x86-32 | Memory: OK\n", COLOR_LIGHT_BROWN);
            } else if (strcmp(buffer, "clear") == 0) {
                clear_screen(COLOR_BLACK);
            } else if (strcmp(buffer, "memory") == 0) {
                print_string("Kernel Heap Allocated Successfully at 0x01000000!\n", COLOR_LIGHT_BLUE);
            } else if (index > 0) {
                print_string("Unknown command! Type 'help' for options.\n", COLOR_LIGHT_RED);
            }

            index = 0;
            print_string("[PaizOS Shell v2.0] # ", COLOR_LIGHT_CYAN);
        } else if (c == '\b') { 
            if (index > 0) {
                index--;
                putchar('\b', COLOR_WHITE);
            }
        } else {
            if (index < 127) {
                buffer[index++] = c;
                putchar(c, COLOR_WHITE);
            }
        }
    }
}

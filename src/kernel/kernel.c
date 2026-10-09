/* ==========================================
 * PaizOS - kernel.c (Version 1.0)
 * ========================================== */

#define VGA_ADDRESS 0xB8000
#define VGA_WIDTH 80
#define VGA_HEIGHT 25

unsigned short* vga_buffer = (unsigned short*)VGA_ADDRESS;
unsigned int cursor_x = 0;
unsigned int cursor_y = 0;

void clear_screen(unsigned char bg_color) {
    for (unsigned int y = 0; y < VGA_HEIGHT; y++) {
        for (unsigned int x = 0; x < VGA_WIDTH; x++) {
            vga_buffer[y * VGA_WIDTH + x] = ' ' | (bg_color << 12);
        }
    }
    cursor_x = 0;
    cursor_y = 0;
}

void print_string(const char* str, unsigned char color) {
    for (unsigned int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            cursor_x = 0;
            cursor_y++;
        } else {
            vga_buffer[cursor_y * VGA_WIDTH + cursor_x] = str[i] | (color << 8);
            cursor_x++;
            if (cursor_x >= VGA_WIDTH) {
                cursor_x = 0;
                cursor_y++;
            }
        }
    }
}

void kernel_main(void) {
    clear_screen(0); // صفحه رو مشکی می‌کنه

    // رنگ زرد پاییزی برای تیترها
    unsigned char autumn_color = 14; 
    unsigned char white_color = 15;

    print_string("====================================================\n", autumn_color);
    print_string("             PaizOS - Version 1.0                   \n", autumn_color);
    print_string("====================================================\n\n", autumn_color);
    
    print_string("[+] Kernel successfully booted in 32-bit mode!\n", 10);
    print_string("[+] Hello Mohammad Javad! Welcome to PaizOS.\n\n", white_color);
    
    print_string("Ready for open-source development... \n", autumn_color);
}

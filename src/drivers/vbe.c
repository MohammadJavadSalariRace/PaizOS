/* ===================================================
 * PaizOS v4.0 - VBE Graphics Engine & Glassmorphism
 * =================================================== */
#include <system.h>

#define VBE_SCREEN_WIDTH  1024
#define VBE_SCREEN_HEIGHT 768
unsigned int* vbe_framebuffer = (unsigned int*)0xFD000000; 

void draw_pixel(int x, int y, unsigned int color) {
    if (x >= 0 && x < VBE_SCREEN_WIDTH && y >= 0 && y < VBE_SCREEN_HEIGHT) {
        vbe_framebuffer[y * VBE_SCREEN_WIDTH + x] = color;
    }
}

void draw_glass_window(int x, int y, int width, int height, unsigned int bg_color) {
    for (int i = y; i < y + height; i++) {
        for (int j = x; j < x + width; j++) {
            draw_pixel(j, i, bg_color | 0x33000000); 
        }
    }
}

void init_vbe_graphics(void) {
    print_string("[+] VBE 32-bit High-Res Graphics Engine Initialized (1024x768).\n", COLOR_LIGHT_GREEN);
}

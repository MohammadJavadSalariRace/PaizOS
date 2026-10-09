#include <system.h>

unsigned char kbd_us[128] = {
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
  '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
     0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',   0,
  '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/',   0, '*',   0, ' '
};

char keyboard_getchar(void) {
    char ch = 0;
    while (!(inb(0x64) & 1)); 
    unsigned char scancode = inb(0x60);
    if (!(scancode & 0x80)) { 
        ch = kbd_us[scancode];
    }
    return ch;
}

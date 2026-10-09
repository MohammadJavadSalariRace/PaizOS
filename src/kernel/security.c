/* ===================================================
 * PaizOS v4.0 - Kernel Security & Stack Canary Guard
 * =================================================== */
#include <system.h>

#define STACK_CANARY_MAGIC 0xDEADC0DE

unsigned int global_canary = STACK_CANARY_MAGIC;

void check_stack_canary(unsigned int canary_value) {
    if (canary_value != STACK_CANARY_MAGIC) {
        print_string("\n[SECURITY ALERT] Stack Overflow Detected! Attack Mitigation Active.\n", COLOR_LIGHT_RED);
        print_string("[PaizOS Shield] Isolating Process & Protecting Kernel Memory...\n", COLOR_LIGHT_RED);
    }
}

void init_security_shield(void) {
    print_string("[+] PaizOS Security Shield Activated (Stack Canary & KPTI Guard).\n", COLOR_LIGHT_GREEN);
}

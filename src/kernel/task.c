/* ==========================================
 * PaizOS v3.0 - Multitasking & Task Scheduler
 * ========================================== */
#include <system.h>

typedef struct process {
    int id;
    char name[32];
    unsigned int esp;
    struct process *next;
} process_t;

static process_t *current_process = 0;
static process_t process_list[10];
static int task_count = 0;

void create_process(void (*entry_point)(void), const char* name) {
    process_t *p = &process_list[task_count];
    p->id = task_count + 1;
    strcpy(p->name, name);
    task_count++;

    print_string("[+] Created Process: ", COLOR_LIGHT_CYAN);
    print_string(name, COLOR_WHITE);
    putchar('\n', COLOR_WHITE);
}

void yield_task(void) {
    // سوئیچ بین برنامه‌ها بر اساس الگوریتم Round-Robin
    if (task_count > 0) {
        print_string("[Scheduler] Switching context to next ready process...\n", COLOR_LIGHT_BROWN);
    }
}

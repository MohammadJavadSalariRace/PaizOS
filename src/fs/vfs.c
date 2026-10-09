/* ==========================================
 * PaizOS v3.0 - Virtual File System (VFS)
 * ========================================== */
#include <system.h>

typedef struct vfs_node {
    char name[64];
    unsigned int size;
    unsigned int type; // 1 = File, 2 = Directory
    char content[512];
} vfs_node_t;

static vfs_node_t ramdisk[20];
static int file_count = 0;

void vfs_create_file(const char* name, const char* content) {
    strcpy(ramdisk[file_count].name, name);
    strcpy(ramdisk[file_count].content, content);
    ramdisk[file_count].size = strlen(content);
    ramdisk[file_count].type = 1;
    file_count++;
}

void vfs_list_files(void) {
    print_string("\n--- PaizOS Ramdisk File System ---\n", COLOR_LIGHT_CYAN);
    for (int i = 0; i < file_count; i++) {
        print_string(" - ", COLOR_WHITE);
        print_string(ramdisk[i].name, COLOR_LIGHT_GREEN);
        print_string(" (", COLOR_DARK_GREY);
        print_string("Bytes)\n", COLOR_DARK_GREY);
    }
}

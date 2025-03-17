#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

int main() {
    FILE *file = fopen("output/result.txt", "w");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    fprintf(file, "Size of size_t: %zu bytes (%zu bits)\n", sizeof(size_t), sizeof(size_t) * 8);

    size_t max_alloc = SIZE_MAX;
    fprintf(file, "Trying to allocate %zu bytes...\n", max_alloc);

    void *ptr = malloc(max_alloc);
    if (ptr) {
        fprintf(file, "Memory allocation successful!\n");
        free(ptr);
    } else {
        fprintf(file, "Memory allocation failed.\n");
    }
    fclose(file);

    return 0;
}

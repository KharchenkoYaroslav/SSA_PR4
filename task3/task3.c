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

    fprintf(file, "Testing malloc(0)\n");
    void *zero_alloc = malloc(0);
    if (zero_alloc) {
        fprintf(file, "malloc(0) returned non-NULL pointer, freeing it.\n");
        free(zero_alloc);
    } else {
        fprintf(file, "malloc(0) returned NULL.\n");
    }

    fclose(file);
    return 0;
}

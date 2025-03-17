#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

void test_malloc(FILE *file, size_t size) {
    fprintf(file, "Trying to allocate %zu bytes...\n", size);
    void *ptr = malloc(size);

    if (ptr) {
        fprintf(file, "Memory allocation successful!\n");
        free(ptr);
    } else {
        fprintf(file, "Memory allocation failed.\n");
    }
}

int main() {
    FILE *file = fopen("output/result.txt", "w");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    int negative = -1;
    test_malloc(file, (size_t)negative);

    int xa = 1000000;  
    int xb = 1000000;  
    int num_signed = xa * xb; 

    fprintf(file, "num_signed = %d (можливе переповнення)\n", num_signed);
    test_malloc(file, (size_t)num_signed); 

    fclose(file);
    return 0;
}
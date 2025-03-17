#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("output/result.txt", "w");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    size_t size = 1024;
    void *ptr = malloc(size);
    if (!ptr) {
        fprintf(file, "Initial allocation failed\n");
        return 1;
    }

    fprintf(file, "Memory allocated\n");

    ptr = realloc(ptr, 1024 * 1024 * 1024 * 1024); 

    if (!ptr) { 
        fprintf(file, "Memory reallocation failed, but original pointer is lost!\n");
        return 1;
    }

    fprintf(file, "Memory reallocated successfully\n");
    free(ptr); 
    return 0;
}

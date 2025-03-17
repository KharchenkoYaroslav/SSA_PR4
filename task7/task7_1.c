#include <stdlib.h>
#include <stdio.h>

struct sbar {
    int data;
};

int main() {
    FILE *file = fopen("output/result_1.txt", "w");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    struct sbar *ptr, *newptr;

    ptr = calloc(1000, sizeof(struct sbar));
    if (!ptr) {
        perror("calloc failed");
        return 1;
    }

    newptr = realloc(ptr, 500*sizeof(struct sbar));
    if (!newptr) {
        perror("realloc failed");
        free(ptr);
        return 1;
    }

    fprintf(file, "Memory successfully reallocated using realloc.\n");
    free(newptr);

    return 0;
}

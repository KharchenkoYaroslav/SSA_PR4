#include <stdlib.h>
#include <stdio.h>

struct sbar {
    int data;
};

int main() {
    FILE *file = fopen("output/result_2.txt", "w");
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

    newptr = reallocarray(ptr, 500, sizeof(struct sbar));
    if (!newptr) {
        perror("reallocarray failed");
        free(ptr);
        return 1;
    }

    fprintf(file, "Memory successfully reallocated using reallocarray.\n");
    free(newptr);

    return 0;
}

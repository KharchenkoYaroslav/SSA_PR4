#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("output/result_1.txt", "w");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    void *ptr = NULL;
    for (int i = 0; i < 5; i++) {
        if (!ptr) {
            ptr = malloc(10);
            fprintf(file, "Memory allocated at iteration %d\n", i);
        }
        // Проблема: ptr не обнуляється після free
        fprintf(file, "Using ptr at iteration %d\n", i);
        free(ptr);
    }
    return 0;
}

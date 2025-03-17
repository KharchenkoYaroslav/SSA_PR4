#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("output/result_2.txt", "w");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    void *ptr = NULL;
    for (int i = 0; i < 5; i++) {
        if (!ptr) {
            ptr = malloc(10);
            if (ptr == NULL) {
                fprintf(file, "Memory allocation failed\n");
                return 1;
            }
            fprintf(file, "Memory allocated at iteration %d\n", i);
        }
        fprintf(file, "Using ptr at iteration %d\n", i);

        free(ptr);
        ptr = NULL;  
    }
    return 0;
}

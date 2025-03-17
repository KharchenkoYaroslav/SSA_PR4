#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("output/result.txt", "w");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }
    
    void *ptr = NULL;

    ptr = realloc(NULL, 16);
    if (ptr) {
        fprintf(file, "realloc(NULL, 16) успішний, отримано адресу: %p\n", ptr);
    } else {
        fprintf(file, "realloc(NULL, 16) не зміг виділити пам'ять\n");
    }
    free(ptr);

    ptr = malloc(16);
    if (!ptr) {
        fprintf(file, "malloc(16) не зміг виділити пам'ять\n");
        return 1;
    }

    void *new_ptr = realloc(ptr, 0);
    if (new_ptr == NULL) {
        fprintf(file, "realloc(ptr, 0) повернув NULL \n");
    } else {
        fprintf(file, "realloc(ptr, 0) повернув адресу: %p \n", new_ptr);
        free(new_ptr);
    }

    return 0;
}

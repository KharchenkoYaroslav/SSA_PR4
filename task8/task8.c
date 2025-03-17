#include <stdio.h>
#include <unistd.h>

int main() {
    FILE *file = fopen("output/result.txt", "w");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }
    void *initial_brk, *new_brk, *allocated_mem;

    initial_brk = sbrk(0);
    fprintf(file, "Початковий break: %p\n", initial_brk);

    allocated_mem = sbrk(1024);
    if (allocated_mem == (void*) -1) {
        perror("sbrk failed");
        return 1;
    }
    fprintf(file, "Пам'ять виділена за адресою: %p\n", allocated_mem);

    new_brk = sbrk(0);
    fprintf(file, "Новий break: %p\n", new_brk);

    if (brk(initial_brk) != 0) {
        perror("brk failed");
        return 1;
    }
    fprintf(file, "Heap повернуто у початковий стан.\n");

    return 0;
}

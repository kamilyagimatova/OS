#include <stdlib.h>
#include <stdio.h>

void* realloc_new(void* ptr, int size) {
    if (ptr == NULL) {
        ptr = malloc(size);
        return ptr;
    }
    if (size == 0) {
        free(ptr);
        return ptr;
    }
    void* ptr_new = malloc(size);
    for (int i = 0; i < size; i++) {
        ((char*)ptr_new)[i] = ((char*)ptr)[i];
    }
    free(ptr);
    return ptr_new;
}

int main() {
    // for checking
    int* a = malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        a[i] = i + 100;
    }
    a = realloc_new(a, 9 * sizeof(int));
    for (int i = 0; i < 9; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
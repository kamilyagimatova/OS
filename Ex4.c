#include <stdio.h>

int main()
{
    int a, b;
    puts("Please, write a and b: ");
    scanf("%d%d", &a, &b);
    swap(&a, &b);
    printf("%d %d", a, b);
    return 0;
}

void swap(int* a, int* b) {
    int k = *a;
    *a = *b;
    *b = k;
}
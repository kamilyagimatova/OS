#include <stdio.h>

int main()
{
    int n;
    puts("Please, print n: ");
    scanf("%d", &n);
    puts("Your triangle: ");
    for (int i = 0; i < n; i++) {
        int amountOfStar = 2 * i + 1;
        int amountOfSpace = n - 1 - i;
        for (int j = 0; j < amountOfSpace; j++) {
            printf("%c", ' ');
        }
        for (int j = 0; j < amountOfStar; j++) {
            printf("%c", '*');
        }
        for (int j = 0; j < amountOfSpace; j++) {
            printf("%c", ' ');
        }
        printf("\n");
    }
    return 0;
}

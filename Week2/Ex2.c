#include <stdio.h>
#include <string.h>

int main() {
    char string[256];
    puts("Please, print string: ");
    gets(string);
    puts("The reverse string: ");
    for (int i = strlen(string) - 1; i >= 0; i--) {
        putchar(string[i]);
    }
    return 0;
}
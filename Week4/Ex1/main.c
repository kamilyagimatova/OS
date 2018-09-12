#include <stdio.h>
#include <unistd.h>

int main() {
    int n = 5;
    switch (fork()) {
        case 0:
            printf("Hello from child [%d]\n", getpid() - n);
            return 0;
        default:
            printf("Hello from parent [%d]\n", getpid() - n);
    }
    return 0;
}
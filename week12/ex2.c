#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <memory.h>
#include <malloc.h>

#define MAX_SIZE 10000

int main(int argc, char* argv[])  {
    int is_append = (argc > 1 && !strcmp(argv[1], "-a"));

    char* buf = malloc(MAX_SIZE * sizeof(char));
    read(0, buf, MAX_SIZE);


    for (int i = 0; i < argc - 1 - is_append; i++) {
        FILE* file = malloc(sizeof(FILE));
        if (is_append) {
            file = fopen(argv[i + 2], "a");
        } else {
            file = fopen(argv[i + 1], "w");
        }
        fputs(buf, file);
    }
}

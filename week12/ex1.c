#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define ARRAY_SIZE 20

int main() {
    int randomData = open("/dev/random", O_RDONLY);
    if (randomData < 0) {
        printf("Error with open /dev/random");
    }
    else
    {
        char rand[ARRAY_SIZE];
        ssize_t result = read(randomData, rand, 20);
        if (result < 0)
        {
            printf("Error with open generating random values");
        }
        close(randomData);
        printf("%s", rand);
    }
}
ex1.txt


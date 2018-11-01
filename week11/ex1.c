#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>


#define FILEPATH "ex1.txt"
#define SIZE 19
#define FILESIZE (SIZE * sizeof(char))


int main()
{
    int i;
    int fd;
    char string[SIZE] = "This is a nice day\n";

    
    fd = open(FILEPATH, O_RDWR);
    write(fd, "", SIZE);


    char* map = (char*)mmap(0, FILESIZE, PROT_WRITE, MAP_SHARED, fd, 0);
    for (int i = 0; i < SIZE; i++) {
 	map[i] = string[i];
    }

    munmap(map, SIZE);
    close(fd);

    return 0;
}


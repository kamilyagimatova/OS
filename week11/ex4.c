#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>

#define P1 "ex1.txt"
#define P2 "ex1.memcpy.txt"

int main() {
	int fd1 = open(P1, O_RDONLY);
	int fd2 = open(P2, O_RDWR | O_CREAT, S_IRWXU);
	
	struct stat st1;
	stat(P1, &st1);
	int len = st1.st_size;

	write(fd2, "", 20);

	char *f1 = (char*)mmap(0, len, PROT_READ, MAP_SHARED, fd1, 0);
	char *f2 = (char*)mmap(0, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd2, 0);

	memcpy(f2, f1, 20);

	munmap(f1, len);
	munmap(f2, len);
	close(fd1);
	close(fd2);
	return 0;
}

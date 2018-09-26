#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int fd[2];

int main() {
    int const size = 9;
	
	char s1[] = "Some text";
	char s2[size];

	if (pipe(fd) == -1) {
		printf("Error of creating a pipe.\n");
		exit(1);
	}

	write(fd[1], s1, size);
	read(fd[0], s2, size);

	printf("string1: %s\nstring2: %s\n", s1, s2);

	return 0;
}
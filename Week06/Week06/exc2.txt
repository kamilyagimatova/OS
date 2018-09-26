#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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
	printf("string1: %s\n", s1);
	
	pid_t pid = fork();

	if (pid == 0) {
		read(fd[0], s2, size + 1);
		printf("string2: %s\n", s2);
	} else {
		int status = 0;
		wait(&status);
	}


	return 0;
}
#include <stdio.h>
#include <unistd.h>

#define SIZE 5

int main() {
	setvbuf(stdout, NULL, _IOLBF, 0);
	char str[SIZE] = "Hello";

	for (int i = 0; i < SIZE; i++) {
		printf("%c", str[i]);
		sleep(1);	
	}

	return 0;
}

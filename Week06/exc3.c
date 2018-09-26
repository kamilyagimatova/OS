#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

static void handler(int signum) {
	printf("CtrlC\n");
	exit(0);
}

int main() {
	struct sigaction sa;
	sa.sa_handler = handler;
	
	sigaction(SIGINT, &sa, NULL);

	while(1) { }
}
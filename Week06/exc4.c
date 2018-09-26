#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

static void handler(int signum) {
    printf("handler\n");
    exit(0);
}

int main() {
    printf("");
    printf("%d\n", getpid());
    struct sigaction sa;
    sa.sa_handler = handler;

    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGKILL, &sa, NULL);
    sigaction(SIGSTOP, &sa, NULL);
    sigaction(SIGUSR1, &sa, NULL);

    while (1) {}
}


// after kill it writes "handler" (string in my void)
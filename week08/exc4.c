#include <malloc.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    struct rusage rusage;
    size_t bytes = 1024 * 1024 * 10;
    int* data;
    for (int i = 0; i < 10; i++) {
        data = (int *) malloc(bytes);
        memset(data, 0, bytes);
        getrusage(RUSAGE_SELF, &rusage);
        printf("Mem: %ld\n", rusage.ru_maxrss);
        sleep(1);
    }
    return 0;
}
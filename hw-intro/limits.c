#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit lim;

    if (getrlimit(RLIMIT_STACK, &lim) == 0) {
        printf("stack size: %lu bytes\n", lim.rlim_cur);
    } else {
        perror("getrlimit RLIMIT_STACK");
    }

    if (getrlimit(RLIMIT_NPROC, &lim) == 0) {
        printf("process limit: %lu\n", lim.rlim_cur);
    } else {
        perror("getrlimit RLIMIT_NPROC");
    }

    if (getrlimit(RLIMIT_NOFILE, &lim) == 0) {
        printf("max file descriptors: %lu\n", lim.rlim_cur);
    } else {
        perror("getrlimit RLIMIT_NOFILE");
    }

    return 0;
}

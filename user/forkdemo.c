#include "kernel/fcntl.h"
#include "kernel/types.h"
#include "user/user.h"

int main() {
    int pid;

    pid = fork();
    if (pid == 0) {
        close(1);
        open("output2.txt", O_WRONLY | O_CREATE);
        char *argv[] = {"echo", "this is ", "a sep proc", 0};
        exec("echo", argv);
        printf("exec failed!\n");
        exit(1);
    } else {
        wait((int *) 0);
    }

    exit(0);
}

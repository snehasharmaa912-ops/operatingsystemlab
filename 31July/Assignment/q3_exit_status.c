//Child exits with status 10, parent reads it with wait()

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        printf("[Child - PID: %d] Exiting with status 10\n", getpid());
        exit(10);
    } else {
        int status;
        wait(&status);

        if (WIFEXITED(status)) {
            printf("[Parent] Child exited normally with status: %d\n", WEXITSTATUS(status));
        } else {
            printf("[Parent] Child did not exit normally\n");
        }
    }
    return 0;
}

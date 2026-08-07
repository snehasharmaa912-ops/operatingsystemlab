//Demonstrate an orphan process

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        printf("[Child - PID: %d] PPID before parent exits: %d\n", getpid(), getppid());
        sleep(3); 
        printf("[Child - PID: %d] PPID after parent exits: %d\n", getpid(), getppid());
    } else {
        printf("[Parent - PID: %d] Terminating now...\n", getpid());
        exit(0);
    }
    return 0;
}

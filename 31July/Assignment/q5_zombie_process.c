//Demonstrate a zombie process (observe with ps)

#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        printf("[Child - PID: %d] Exiting now...\n", getpid());
        _exit(0);
    } else {
        printf("[Parent - PID: %d] Child PID: %d is now a zombie.\n", getpid(), pid);
        printf("Run: ps -el | grep Z    (in another terminal, within 30s)\n");
        sleep(30); 
        printf("[Parent] Done sleeping, zombie will be cleaned up on exit.\n");
    }
    return 0;
}

// Print PID and PPID of both processes
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        printf("Child Process -> PID: %d, PPID: %d\n", getpid(), getppid());
    } else {
        wait(NULL);
        printf("Parent Process -> PID: %d, PPID: %d\n", getpid(), getppid());
    }
    return 0;
}

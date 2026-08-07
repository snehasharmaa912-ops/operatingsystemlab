//fork(), exec(), wait() to run date command

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        printf("[Child - PID: %d] Executing 'date' command:\n", getpid());
        execlp("date", "date", NULL);
        perror("exec failed");
        return 1;
    } else {
        wait(NULL);
        printf("[Parent - PID: %d] Child finished executing date command.\n", getpid());
    }
    return 0;
}

//Child prints 1 to 5, parent waits using wait()

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        printf("[Child Process - PID: %d]\n", getpid());
        for (int i = 1; i <= 5; i++) {
            printf("%d ", i);
        }
        printf("\n");
    } else {
        wait(NULL);
        printf("[Parent Process - PID: %d] Child finished execution.\n", getpid());
    }
    return 0;
}

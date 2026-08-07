//Parent prints even (1–20), child prints odd (1–20)

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        printf("[Child - PID: %d] Odd numbers 1 to 20: ", getpid());
        for (int i = 1; i <= 20; i += 2) {
            printf("%d ", i);
        }
        printf("\n");
    } else {
        wait(NULL);
        printf("[Parent - PID: %d] Even numbers 1 to 20: ", getpid());
        for (int i = 2; i <= 20; i += 2) {
            printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}

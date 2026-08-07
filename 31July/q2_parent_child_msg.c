//Print "Parent Process" / "Child Process" using fork() return value

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        printf("Child Process\n");
    } else {
        wait(NULL);
        printf("Parent Process\n");
    }
    return 0;
}

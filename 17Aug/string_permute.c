#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permute(char *str, int l, int r) {
    if (l == r) {
        printf("%s\n", str);
        return;
    }
    for (int i = l; i <= r; i++) {
        swap(&str[l], &str[i]);
        permute(str, l + 1, r);
        swap(&str[l], &str[i]);
    }
}

int main() {
    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe failed");
        exit(1);
    }
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0) {
        close(fd[0]);
        char str[100];
        printf("Enter a string: ");
        scanf("%99s", str);
        write(fd[1], str, strlen(str) + 1);
        close(fd[1]);
        exit(0);
    }
    else {
        close(fd[1]);
        wait(NULL);
        char buffer[100];
        read(fd[0], buffer, sizeof(buffer));
        close(fd[0]);
        printf("Parent (PID %d): Permutations of \"%s\":\n", getpid(), buffer);
        permute(buffer, 0, strlen(buffer) - 1);
    }
    return 0;
}

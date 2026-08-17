#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
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
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];
        printf("Child (PID %d): sum of elements = %d\n", getpid(), sum);
        write(fd[1], &sum, sizeof(sum));
        close(fd[1]);
        exit(0);
    }
    else {
        close(fd[1]);
        wait(NULL);
        int sum;
        read(fd[0], &sum, sizeof(sum));
        close(fd[0]);
        printf("Parent (PID %d): received sum = %d\n", getpid(), sum);
        if (isPrime(sum))
            printf("Parent: %d is a PRIME number.\n", sum);
        else
            printf("Parent: %d is NOT a prime number.\n", sum);
    }
    return 0;
}

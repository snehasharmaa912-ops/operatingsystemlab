#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

long factorial(int n) {
    long result = 1;
    for (int i = 1; i <= n; i++) result *= i;
    return result;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        printf("\n[Child Process]\n");
        printf("PID: %d, Parent PID: %d\n", getpid(), getppid());
        if (isPrime(n))
            printf("%d is a Prime number\n", n);
        else
            printf("%d is NOT a Prime number\n", n);
    } else {
        wait(NULL);
        printf("\n[Parent Process]\n");
        printf("PID: %d, Child PID: %d\n", getpid(), pid);
        printf("Factorial of %d is %ld\n", n, factorial(n));
    }
    return 0;
}

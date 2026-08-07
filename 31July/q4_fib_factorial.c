//Child prints Fibonacci, parent calculates factorial
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void fibonacci(int n) {
    int a = 0, b = 1, next;
    printf("Fibonacci series up to %d terms:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", a);
        next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

long factorial(int n) {
    long result = 1;
    for (int i = 1; i <= n; i++) result *= i;
    return result;
}

int main() {
    int n;
    printf("Enter value of n: ");
    scanf("%d", &n);
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        printf("\n[Child Process - PID: %d]\n", getpid());
        fibonacci(n);
    } else {
        wait(NULL);
        printf("\n[Parent Process - PID: %d]\n", getpid());
        printf("Factorial of %d is %ld\n", n, factorial(n));
    }
    return 0;
}

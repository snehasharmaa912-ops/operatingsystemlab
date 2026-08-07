//Child prints Fibonacci and creates grandchild for factorial; parent computes sum of first n naturals
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

int sumOfNaturals(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += i;
    return sum;
}

int main() {
    int n;
    printf("Enter value of n: ");
    scanf("%d", &n);
    pid_t pid1 = fork();
    if (pid1 < 0) {
        perror("fork failed");
        return 1;
    } else if (pid1 == 0) {
        printf("\n[Child Process - PID: %d, PPID: %d]\n", getpid(), getppid());
        fibonacci(n);

        pid_t pid2 = fork();
        if (pid2 < 0) {
            perror("fork failed");
            exit(1);
        } else if (pid2 == 0) {
            printf("\n[Grandchild Process - PID: %d, PPID: %d]\n", getpid(), getppid());
            printf("Factorial of %d is %ld\n", n, factorial(n));
        } else {
            wait(NULL);
        }
    } else {
        wait(NULL);
        printf("\n[Parent Process - PID: %d]\n", getpid());
        printf("Sum of first %d natural numbers is %d\n", n, sumOfNaturals(n));
    }
    return 0;
}

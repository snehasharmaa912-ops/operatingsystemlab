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

int isArmstrong(int num) {
    int original = num, digits = 0, sum = 0, remainder, temp = num;
    while (temp != 0) { digits++; temp /= 10; }
    temp = num;
    while (temp != 0) {
        remainder = temp % 10;
        int power = 1;
        for (int i = 0; i < digits; i++) power *= remainder;
        sum += power;
        temp /= 10;
    }
    return (sum == original);
}

void armstrong(int n) {
    printf("Armstrong numbers up to %d:\n", n);
    for (int i = 1; i <= n; i++) {
        if (isArmstrong(i)) printf("%d ", i);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        printf("\n[Child Process - PID: %d]\n", getpid());
        fibonacci(n);
    } else {
        wait(NULL);
        printf("\n[Parent Process - PID: %d]\n", getpid());
        armstrong(n);
    }
    return 0;
}

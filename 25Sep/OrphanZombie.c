//C Program to demonstrate Zombie Process 

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t pid = fork();
    if (pid < 0)
    {
        printf("Fork failed\n");
    }
    else if (pid == 0)
    {
        printf("Child process: PID = %d\n", getpid());
        printf("Child is exiting...\n");
        exit(0);
    }
    else
    {
        printf("Parent process: PID = %d\n", getpid());
        sleep(10);
        printf("Parent is calling wait()...\n");
        wait(NULL);
        printf("Parent process finished.\n");
    }
    return 0;
}

//C program to demonstrate Orphan Process 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        sleep(5);
        printf("Child PID = %d\n", getpid());
        printf("Parent PID = %d\n", getppid());
        printf("Child has become an orphan.\n");
    }
    else
    {
        printf("Parent PID = %d\n", getpid());
        printf("Parent is exiting...\n");
        exit(0);
    }
    return 0;
}

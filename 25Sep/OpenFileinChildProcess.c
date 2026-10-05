//C program to open a file in the child process

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
    pid_t pid = fork();
    if (pid < 0)
    {
        printf("Fork failed\n");
        return 1;
    }
    if (pid == 0)
    {
        int fd = open("file.txt", O_RDONLY);
        if (fd < 0)
        {
            printf("File could not be opened\n");
            exit(1);
        }
        printf("File opened successfully by child process.\n");
        printf("Child PID = %d\n", getpid());
        close(fd);
    }
    else
    {
        printf("Parent process: PID = %d\n", getpid());
    }
    return 0;
}

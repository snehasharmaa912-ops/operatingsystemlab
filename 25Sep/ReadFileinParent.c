// Print end numbers, pass filename from parent and read file content in parent 

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
    int pipefd[2];
    pid_t pid;
    char filename[100];
    if (pipe(pipefd) == -1)
    {
        printf("Pipe creation failed\n");
        return 1;
    }
    pid = fork();
    if (pid < 0)
    {
        printf("Fork failed\n");
        return 1;
    }
    if (pid == 0)
    {
        close(pipefd[1]);
        read(pipefd[0], filename, sizeof(filename));
        close(pipefd[0]);
        printf("Child Process:\n");
        printf("Filename received from parent: %s\n", filename);
        printf("Even numbers:\n");
        for (int i = 2; i <= 20; i += 2)
        {
            printf("%d ", i);
        }
        printf("\n");
    }
    else
    {
        close(pipefd[0]);
        printf("Parent Process\n");
        printf("Enter filename: ");
        scanf("%99s", filename);
        write(pipefd[1], filename, sizeof(filename));
        close(pipefd[1]);
        wait(NULL);
        int fd = open(filename, O_RDONLY);
        if (fd < 0)
        {
            printf("File could not be opened\n");
            return 1;
        }
        char buffer[1000];
        int bytes;
        printf("\nContent of file:\n");
        while ((bytes = read(fd, buffer, sizeof(buffer) - 1)) > 0)
        {
            buffer[bytes] = '\0';
            printf("%s", buffer);
        }
        close(fd);
    }
    return 0;
}

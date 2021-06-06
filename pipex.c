#include "pipex.h"
#include <sys/wait.h>

int main(int argc, char **argv, char **env)
{
    pid_t pid1;
    int fd[2];

    if (pipe(fd) == -1)
        printf("pipe failed\n");
    pid1 = fork();
    if (pid1 == -1)
        printf("fork failed\n");
    if (pid1 == 0)
    {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        execlp("ping", "ping", "-c", "5", "google.com", NULL);
    }
    else
    {
        int out = open("file2", O_WRONLY | O_CREAT , 0777);
        wait(0);
        dup2(out, STDOUT_FILENO);
        close(out);
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
        execlp("cat", "cat", NULL);
    }

    close(fd[0]);
    close(fd[1]);

    waitpid(pid1, NULL, 0);
}
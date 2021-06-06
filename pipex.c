#include "pipex.h"
#include <sys/wait.h>

int main(int argc, char **argv, char **env)
{
    pid_t pid;
    t_pipex pipex;
    int fd[2];
    int i;
    char **paths;

    paths = path_finder(argv, env);
    //parse_argv(argv, 0 , &pipex);
    if (pipe(fd) == -1)
        printf("pipe failed\n");
    pid = fork();
    if (pid == -1)
        printf("fork failed\n");
    if (pid == 0)
    {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        i = 0;
        while (paths[i])
        {
            paths[i] = ft_strjoin(paths[i], "/");
            paths[i] = ft_strjoin(paths[i], "ls");
            execve(paths[i], argv, NULL);
            i++;
        }
        free(pipex.cmd);
    }
    else
    {
      //  parse_argv(argv, 1, &pipex);
        int out = open("file2", O_WRONLY | O_CREAT , 0777);
        wait(0);
        dup2(out, STDOUT_FILENO);
        close(out);
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
        i = 0;
        while (paths[i])
        {
            paths[i] = ft_strjoin(paths[i], "/");
            paths[i] = ft_strjoin(paths[i], "ls");
            execve(paths[i], argv, NULL);
            i++;
        }
    }
    printf("%s\n %s\n %s\n",argv[0], argv[1], argv[2]);
    close(fd[0]);
    close(fd[1]);
    waitpid(pid, NULL, 0);
}
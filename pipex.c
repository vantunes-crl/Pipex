#include "pipex.h"

int main(int argc, char **argv, char **env)
{
    pid_t pid;
    int fd[2];
    int i;
    char **paths;

    if (pipe(fd) == -1)
        printf("pipe failed\n");
    pid = fork();
    if (pid == -1)
        printf("fork failed\n");
    paths = path_finder(argv, env);
    if (pid == 0)
    {
        char *new_str;
        char **args;
        new_str = ft_joinspace(argv[2], argv[1]);
        args = ft_split(new_str, ' ');
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        i = 0;
        while (paths[i])
        {
            paths[i] = ft_strjoin(paths[i], "/");
            paths[i] = ft_strjoin(paths[i], args[0]);
            execve(paths[i], args, NULL);
            i++;
        }
    }

    pid_t pid2;
    pid2 = fork();
    if (pid2 == 0)
    {
        char **args2;
        int out = open("file2", O_WRONLY | O_CREAT , 0777);
        args2 = ft_split(argv[3], ' ');
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
            paths[i] = ft_strjoin(paths[i], args2[0]);
            execve(paths[i], args2, NULL);
            i++;
        }
    }
    close(fd[0]);
    close(fd[1]);
    waitpid(pid2, NULL, 0);
    waitpid(pid, NULL, 0);
}
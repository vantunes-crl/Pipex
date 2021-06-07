#include "pipex.h"

static void call_parent(char **argv, int *fd, char **env)
{
    char    **args;
    char    **paths;
    int     out;
    int     i;

    out = open(argv[4], O_WRONLY | O_CREAT , 0777);
    paths = path_finder(argv, env);
    args = ft_split(argv[3], ' ');
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
        paths[i] = ft_strjoin(paths[i], args[0]);
        execve(paths[i], args, NULL);
        i++;
    }
}

static void call_child(char **argv, int *fd, char **env)
{
    int     i;
    char    **paths;
    char    *new_str;
    char    **args;

    paths = path_finder(argv, env);
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

int main(int argc, char **argv, char **env)
{
    pid_t pid;
    int fd[2];
    int i;

    if (pipe(fd) == -1)
        return (1);
    pid = fork();
    if (pid == -1)
        return 1;
    if (pid == 0)
        call_child(argv, fd, env);
    else
        call_parent(argv, fd, env);
    close(fd[0]);
    close(fd[1]);
    waitpid(pid, NULL, 0);
}
#include "pipex.h"

char **parse_argv(char **argv, int cmd, t_pipex *pipex)
{
    char **args;
    int i = 0;

    if (cmd == 0)
        args = ft_split(argv[1], ' ');
    else
        args = ft_split(argv[2], ' ');
    pipex->cmd = ft_strdup(args[0]);
    args[0] = ft_strdup(argv[0]);
    while (args[i])
    {
        args[i] = args[i + 1];
        i++;
    }
    args[i] = NULL;
    return (args);
}
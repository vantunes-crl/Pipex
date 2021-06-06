#include "pipex.h"

char *parse_argv(char **argv, int cmd)
{
    char **args;
    int i = 0;

    if (cmd == 0)
        args = ft_split(argv[1], ' ');
    else
        args = ft_split(argv[2], ' ');
    return (args[0]);
}

char **path_finder(char **argv, char **env)
{
    int i = 0;
    char **paths;
    int ret = 0;

    while(env)
    {
        if (strncmp(env[i], "PATH=", 5) == 0)
        {
            paths = ft_split(env[i] + 5, ':');
            break;
        }
        i++;
    }
    return (paths);
}
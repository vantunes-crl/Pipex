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
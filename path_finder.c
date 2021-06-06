#include "pipex.h"

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
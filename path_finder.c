#include "pipex.h"

char *ft_joinspace(char *s1, char *s2)
{
    char *new_str;
    int i;
    int j;

    i = 0;
    new_str = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 2);
    while (s1[i])
        new_str[i] = s1[i++];
    new_str[i++] = ' ';
    i = 0;
    while(s2[j])
        new_str[i++] = s2[j++];
    new_str[i] = '\0';
    return(new_str);
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
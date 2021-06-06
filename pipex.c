#include "pipex.h"

int main(int argc, char **argv, char **env)
{
    int i = 0;
    char **paths;
    char *arg[] = {argv[0], argv[2]}; 
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
    i = 0;
    while (paths[i])
    {
        paths[i] = ft_strjoin(paths[i], "/");
        paths[i] = ft_strjoin(paths[i], argv[1]);
        ret = execve(paths[i], arg, env);
        i++;
    }

}
#ifndef PIPEX_H
#define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_pipex
{
    char        *cmd;
}              t_pipex;

char	*ft_strdup(const char *s1);
int	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
int     ft_countwords_bonus(const char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char    **path_finder(char **argv, char **env);
char    **parse_argv(char **argv, int cmd, t_pipex *pipex);
#endif
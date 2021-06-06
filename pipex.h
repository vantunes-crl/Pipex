#ifndef PIPEX_H
#define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

/* utils */
char    *ft_strdup(const char *s1);
int     ft_strlen(const char *str);
char    **ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);

/* parse path */
char    **path_finder(char **argv, char **env);
char    *parse_argv(char **argv, int cmd);

#endif
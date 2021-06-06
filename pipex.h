#ifndef PIPEX_H
#define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char	**ft_split(char const *s, char c);
int	ft_countwords_bonus(const char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
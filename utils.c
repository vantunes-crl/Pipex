#include "pipex.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] != '\0' && str1[i] == str2[i] && i < n - 1)
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

char	*ft_strdup(const char *s1)
{
	char	*s1_cpy;
	int		i;

	i = 0;
	s1_cpy = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (s1_cpy == 0)
		return (0);
	while (s1[i])
	{
		s1_cpy[i] = s1[i];
		i++;
	}
	s1_cpy[i] = '\0';
	return (s1_cpy);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*news;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	news = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!news)
		return (NULL);
	while (s1[i] != '\0')
	{
		news[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		news[i] = s2[j];
		j++;
		i++;
	}
	news[i] = '\0';
	return (news);
}

char	*ft_joinspace(char *s1, char *s2)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	new_str = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 2);
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	new_str[i++] = ' ';
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	return (new_str);
}

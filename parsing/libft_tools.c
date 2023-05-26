/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 08:16:10 by nloutfi           #+#    #+#             */
/*   Updated: 2023/05/26 11:48:01 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int     ft_strncmp(char *s1, char *s2, int n)
{
    int i;

    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
        i++;
    if (i == n)
        return (0);
    return (s1[i] - s2[i]);
}

char	*ft_strdup(char *s)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	while (s && s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	word_count(char *str, char c)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] != c && str[i])
		{
			j = 1;
			i++;
		}
		if (j == 1)
			n++;
		if (str[i])
			i++;
	}
	return (n);
}

char	**ft_split(char *line, char c)
{
	int		i;
	int		j;
	int		w;
	char	**tab;

	i = 0;
	w = 0;
	// printf("%d %s\n", word_count(line, c), line);
	tab = (char **)malloc(sizeof(char *) * (word_count(line, c) + 1));
	while (line[i])
	{
		j = 0;
		while (line[i] != c && line[i])
		{
			j++;
			i++;
		}
		if (j > 0)
			tab[w++] = ft_substr(line, i - j, j);
		if (line[i])
			i++;
	}
	tab[w] = NULL;
	return (tab);
}

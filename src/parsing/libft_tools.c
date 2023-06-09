/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 08:16:10 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/13 11:10:03 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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

// void	ft_strchr(char *str, int *i, int *j, char c)
// {
// 	while (str[*i] == c && str[*i])
// 	{
// 		(*i)++;
// 		(*j)++;
// 	}	
// }

char	*find_word(char *line, int *i, int *j, int c)
{
	char	*tmp;

	while (line[*i] != c && line[*i])
	{
		(*i)++;
		(*j)++;
	}
	tmp = ft_substr(line, (*i) - (*j), (*j));
	return (tmp);
}

char	**ft_split(char *line, char c)
{
	int		i;
	int		j;
	int		w;
	char	**tab;
	char	*tmp;

	i = 0;
	w = 0;
	if (word_count(line, c) == 3 && line[ft_strlen(line) - 1] == ',')
		errors("invalid Color");
	tab = (char **)malloc(sizeof(char *) * (word_count(line, c) + 1));
	while (line[i])
	{
		j = 0;
		tmp = find_word(line, &i, &j, c);
		tab[w++] = remove_spc(tmp);
		if (line[i])
			i++;
		free(tmp);
	}
	tab[w] = NULL;
	return (tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tools1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 04:53:37 by nloutfi           #+#    #+#             */
/*   Updated: 2023/04/21 04:55:28 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_split(char *line, char c)
{
	int		i;
	int		j;
	int		w;
	char	**tab;

	i = 0;
	w = 0;
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

int ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 01:20:20 by nloutfi           #+#    #+#             */
/*   Updated: 2023/04/22 14:51:36 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*remove_spc(char *line)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	while (*line == ' ' || *line == '\t')
		line++;
	i = ft_strlen(line) - 1;
	while (line[i] == ' ' || line[i] == '\t')
		i--;
	new = (char *)malloc(sizeof(char) * (i + 2));
	while (line[j] && j <= i)
	{
		new[j] = line[j];
		j++;
	}
	new[++i] = '\0';
	return (new);
}


char	*remove_nl(char *line)
{
	int		i;
	char	*new;

	i = 0;
	while (line[i] != '\n')
		i++;
	new = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		new[i] = line[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maptools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 20:19:28 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/03 20:21:20 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	is_map_el(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (2);
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '1' || line[i] == '0')
		return (1);
	else
		return (0);
}

int	map_height(char **file, int i)
{
	int	height;

	height = 0;
	while (file[i] && is_map_el(file[i]) == 1)
	{
		height++;
		i++;
	}
	return (height);
}

int	map_width(char **map, int i)
{
	int	width;

	width = 0;
	while (map[i] && is_map_el(map[i]) == 1)
	{
		if (ft_strlen(map[i]) > width)
			width = ft_strlen(map[i]);
		i++;
	}
	return (width);
}

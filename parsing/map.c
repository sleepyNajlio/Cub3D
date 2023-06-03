/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 00:52:40 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/03 20:22:45 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	check_map(t_parse *parse)
{
	check_chars(parse->map);
	check_borders(parse);
	check_zero(parse);
	check_player(parse);
}

char	*fill_map_line(char *line, int width)
{
	int		i;
	char	*map_line;

	i = 0;
	map_line = malloc(sizeof(char) * width + 1);
	while (i < width)
	{
		if (line[i] && !ft_isspace(line[i]) && line[i])
			map_line[i] = line[i];
		else
			map_line[i] = '2';
		i++;
	}
	map_line[i] = '\0';
	return (map_line);
}

void	check_rest(char **file, int i)
{
	while (file[i])
	{
		if (file[i][0] != '\0')
			errors("Invalid map");
		i++;
	}
}

void	fill_map(char **map, char **file, int i, int width)
{
	int	j;
	int	k;

	k = 0;
	while (file[i] && is_map_el(file[i]) == 1)
	{
		j = 0;
		map[k] = malloc(sizeof(char) * width + 1);
		while (file[i][j])
		{
			map[k][j] = file[i][j];
			j++;
		}
		while (j < width)
		{
			map[k][j] = '2';
			j++;
		}
		map[k][j] = '\0';
		k++;
		i++;
	}
	map[k] = NULL;
	check_rest(file, i);
}

void	parse_map(t_parse *parse, char **file)
{
	int	i;

	i = 0;
	while (!is_map_el(file[i]))
		i++;
	if (is_map_el(file[i]) == 2)
		errors("map Incomplete");
	parse->map_height = map_height(file, i);
	parse->map_width = map_width(file, i);
	parse->map = (char **)malloc(sizeof(char *) * (parse->map_height + 1));
	fill_map(parse->map, file, i, parse->map_width);
	check_map(parse);
}

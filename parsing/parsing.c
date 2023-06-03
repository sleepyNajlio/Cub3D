/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 08:31:02 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/03 17:56:28 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"



char	**fill_file(int fd)
{
	int		i;
	char	*line;
	char	**tab;

	i = 0;
	tab = (char **)malloc(sizeof(char *) * 10000);
	line = get_next_line(fd);
	while (line)
	{
			tab[i] = remove_nl(line);
			free(line);
			line = get_next_line(fd);
			i++;
	}
	free(line);
	tab[i] = NULL;
	return (tab);
}

void	init_parse(t_parse *parse)
{
	parse->no = NULL;
	parse->so = NULL;
	parse->we = NULL;
	parse->ea = NULL;
	parse->floor = 0;
	parse->ceiling = 0;
	parse->tex = 0;
	parse->map = NULL;
	parse->map_height = 0;
	parse->map_width = 0;
	parse->player = 0;
}
	
t_parse	*parsing(char *path)
{
	int		fd;
	t_parse	*parse;
	char	**file;

	parse = (t_parse *)malloc(sizeof(t_parse));
	init_parse(parse);
	fd = open(path, O_RDONLY);
	file = fill_file(fd);
	identifiers(parse, file);
	parse_map(parse, file);
	return (parse);
}
	
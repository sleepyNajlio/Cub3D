/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-fil <fel-fil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 08:31:02 by nloutfi           #+#    #+#             */
/*   Updated: 2023/05/30 15:51:03 by fel-fil          ###   ########.fr       */
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

void	print_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		printf("%s \n", tab[i]);
		i++;
	}
}

void	print_parse(t_parse *parse)
{
	printf("NO: %s!\n", parse->no);
	printf("SO: %s!\n", parse->so);
	printf("WE: %s!\n", parse->we);
	printf("EA: %s!\n", parse->ea);
	printf("Floor: %d\n", parse->floor);
	printf("Ceiling: %d\n", parse->ceiling);
	printf("tex: %d\n", parse->tex);
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
	// free_tab(file);
	// print_tab(file);
	// print_parse(parse);
	// close(fd);
	// identifiers(parse);
	// parse = fill_idens(tab, parse);
	return (parse);
}
	
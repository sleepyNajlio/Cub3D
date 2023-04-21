/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 08:31:02 by nloutfi           #+#    #+#             */
/*   Updated: 2023/04/21 03:41:31 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*remove_nl(char *line)
{
	int		i;
	char	*new;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	new = ft_substr(line, 0, i);
	return (new);
}
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
			tab[i] = ft_strdup(line);
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
		printf("%s ", tab[i]);
		i++;
	}
}

	
t_parse	*parsing(char *path)
{
	int		fd;
	t_parse	*parse;
	char	**file;

	parse = (t_parse *)malloc(sizeof(t_parse));
	fd = open(path, O_RDONLY);
	file = fill_file(fd);
	// identifiers(parse, file);
	print_tab(file);
	// close(fd);
	// identifiers(parse);
	// parse = fill_idens(tab, parse);
	return (parse);
}
	
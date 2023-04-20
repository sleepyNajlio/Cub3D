/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 08:31:02 by nloutfi           #+#    #+#             */
/*   Updated: 2023/04/20 23:58:15 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// char	*remove_spc(char *line)
// {
// 	int		i;
// 	int		j;
// 	char	*new;

// 	i = 0;
// 	j = 0;
// 	while (*line == ' ' || *line == '\t')
// 		line++;
// 	i = ft_strlen(line) - 1;
// 	while (line[i] == ' ' || line[i] == '\t')
// 		i--;
// 	new = (char *)malloc(sizeof(char) * (i + 2));
// 	while (line[i] && j <= i)
// 	{
// 		new[i] = line[i];
// 		i++;
// 	}
// 	new[i] = '\0';
// 	return (new);
// }

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
		line = remove_nl(line);
		if (line[0] != '\0')
		{
			tab[i] = ft_strdup(line);
			free(line);
		}
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
		printf("%s .", tab[i]);
		i++;
	}
}

t_data	*init_idens(t_data *iden)
{
	iden->no = 0;
	iden->so = 0;
	iden->we = 0;
	iden->ea = 0;
	iden->floor = 0;
	iden->ceiling = 0;
	return (iden);
}


int is_iden(char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
		return (1);
	else if (line[0] == 'S' && line[1] == 'O')
		return (2);
	else if (line[0] == 'W' && line[1] == 'E')
		return (3);
	else if (line[0] == 'E' && line[1] == 'A')
		return (4);
	else if (line[0] == 'F' && line[1] == ' ')
		return (5);
	else if (line[0] == 'C' && line[1] == ' ')
		return (6);
	else
		return (0);
}

int invalid_char (char c)
{
	if (c != ' ' && c != '1' && c != '0' && c != 'N' && c != 'S' && c != 'W' && c != 'E')
		return (1);
	return (0);
}

char *invalid_line(char *line)
{
	int i;

	i = 0;
	if (is_iden(line) == 0)
	{
		while (line[i])
		{
			if (invalid_char(line[i]) == 1)
				return (1);
			i++;
		}
	}
	return (0);
}

void	check_data(char **tab, t_data *iden)
{
	int i;

	i = 0;
	iden = init_idens(iden);
	while (tab[i])
	{
		if (is_iden(tab[i]) == 1)
			iden->no++;
		else if (is_iden(tab[i]) == 2)
			iden->so++;
		else if (is_iden(tab[i]) == 3)
			iden->we++;
		else if (is_iden(tab[i]) == 4)
			iden->ea++;
		else if (is_iden(tab[i]) == 5)
			iden->floor++;
		else if (is_iden(tab[i]) == 6)
			iden->ceiling++;
		else if (invalid_line(tab[i]) == 1)
			iden->invalid++;
		i++;
	}
}

// void	data(t_parse *parse)
// {
// 	t_data *iden;
	
// 	iden = (t_data *)malloc(sizeof(t_data));
// 	init_idens(iden);
// 	check_data(parse->tab, iden);
// }


t_parse	*parsing(char *path)
{
	int		fd;
	t_parse	*parse;
	char	**file;

	parse = (t_parse *)malloc(sizeof(t_parse));
	fd = open(path, O_RDONLY);
	file = fill_file(fd);
	print_tab(file);
	close(fd);
	// identifiers(parse);
	// parse = fill_idens(tab, parse);
	return (parse);
}
	
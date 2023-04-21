/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifiers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 00:32:10 by nloutfi           #+#    #+#             */
/*   Updated: 2023/04/21 04:58:38 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	*init_data(t_data *iden)
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
    while (*line == ' ' || *line == '\t')
        line++;
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
    else if (line[0] == '1' || line[0] == '0')
        return (7);
	else
		return (0);
}

void	get_identifiers(char **tab, t_data *iden)
{
	int i;

	i = 0;
	iden = init_idens(iden);
	while (tab[i] && is_iden(tab[i]) != 7)
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
		i++;
	}
}

char *get_color(char *line)
{
	int i;
	char **color;

	i = 0;
	line = remove_spc(line);
	color = ft_split(line, ',');
	while (color[i])
	{
		if (ft_isdigit(color[i]) == 0 || ft_strlen(color[i]) > 3 || ft_strlen(color[i]) < 1
			|| ft_atoi(color[i]) > 255 || ft_atoi(color[i]) < 0)
			errors("invalid Color");
		i++;
	}
}

void    fill_idens(char **file, t_parse *parse, t_data *iden)
{
    int i;

    i = 0;
    while (file[i])
    {
        if (check(file[i], iden) == 1)
            parse->no = remove_spc(file[i] + 2);
        else if (is_iden(file[i]) == 2 && iden->so == 1)
            parse->so = remove_spc(file[i] + 2);
        else if (is_iden(file[i]) == 3 && iden->we == 1)
            parse->we = remove_spc(file[i] + 2);
        else if (is_iden(file[i]) == 4 && iden->ea == 1)
            parse->ea = remove_spc(file[i] + 2);
        else if (is_iden(file[i]) == 5 && iden->floor == 1)
            parse->floor = get_color(file[i] + 1);
        else if (is_iden(file[i]) == 6 && iden->ceiling == 1)
            parse->ceiling = remove_spc(file[i] + 1);
		i++;
    }
}

void    check_identifiers(t_parse *parse, t_data *iden)
{
	int fd;

    if (iden->no != 1 || iden->so != 1 || iden->we != 1 
		|| iden->ea != 1 || iden->floor != 1 || iden->ceiling != 1)
        errors(1);
	if ((fd = open(parse->no, O_RDONLY)) == -1)
		errors(2);
	if ((fd = open(parse->so, O_RDONLY)) == -1)
		errors(2);
	if ((fd = open(parse->we, O_RDONLY)) == -1)
		errors(2);
	if ((fd = open(parse->ea, O_RDONLY)) == -1)
		errors(2);
	
    
}

void	identifiers(t_parse *parse, char **file)
{
	t_data *data;
	
	data = (t_data *)malloc(sizeof(t_data));
	get_identifiers(file, data);
	fill_idens(file, parse, data);
    check_identifiers(parse ,data);
    print_tab(file);
    
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifiers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 00:32:10 by nloutfi           #+#    #+#             */
/*   Updated: 2023/04/22 20:52:55 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    check_identifiers(t_parse *parse)
{
	if (parse->tex != 6)
		errors("invalid elements");
	if (ft_strncmp(parse->no + ft_strlen(parse->no) - 4, ".xpm", 4) != 0
		|| ft_strncmp(parse->so + ft_strlen(parse->so) - 4, ".xpm", 4) != 0
		|| ft_strncmp(parse->we + ft_strlen(parse->we) - 4, ".xpm", 4) != 0
		|| ft_strncmp(parse->ea + ft_strlen(parse->ea) - 4, ".xpm", 4) != 0)
		errors("invalid texture extension");
	if ((open(parse->no, O_RDONLY)) == -1 || (open(parse->so, O_RDONLY)) == -1 
		|| (open(parse->we, O_RDONLY)) == -1 || (open(parse->ea, O_RDONLY)) == -1)
		errors("invalid path");
}

int is_map_line(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '1' || line[i] == '0')
		return (1);
	return (0);
}

int     is_empty_line(char *line)
{
    int i;
    
    i = 0;
    while (ft_isspace(line[i]))
        i++;
    if (line[i] == '\0' || line[i] == '\n')
        return (1);
    else
        return (0);
}

int is_iden(char *line, t_parse *parse)
{
    while (ft_isspace(*line))
        line++;
    if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0 
        || ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0)
    {
        get_tex(line, parse);
        parse->tex++;
        return (1);
    }
    else if (ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0)
    {
        get_color(line, parse);
        parse->tex++;
        return (1);
    }
    else
        return (0);
}

void	identifiers(t_parse *parse, char **file)
{
	int i;

	i = 0;
	while (file[i])
	{
		if (is_map_line(file[i]) == 1)
			break ;
		if (is_empty_line(file[i]) == 1)
			;
		else if (is_iden(file[i], parse) == 0)
			errors("invalid element");
		i++;
	}
    check_identifiers(parse);
}

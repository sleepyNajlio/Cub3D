/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iden_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:37:43 by nloutfi           #+#    #+#             */
/*   Updated: 2023/04/25 13:47:58 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void    get_tex(char *line, t_parse *parse)
{
    if (strncmp(line, "NO", 2) == 0)
        parse->no = remove_spc(line + 2);
    if (strncmp(line, "SO", 2) == 0)
       parse->so = remove_spc(line + 2);
    if (strncmp(line, "WE", 2) == 0)
       parse->we = remove_spc(line + 2);
    if (strncmp(line, "EA", 2) == 0)
       parse->ea = remove_spc(line + 2);
}

char **check_color(char *line)
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
    if (i != 3)
        errors("invalid Color");
    return (color);
}

void	get_color(char *line, t_parse *parse)
{
	int i;
	char **color;
	int red;
	int green;
	int blue;
	
	i = 0;
	color = check_color(line + 1);
	red = ft_atoi(color[0]);
	green = ft_atoi(color[1]);
	blue = ft_atoi(color[2]);
    if (ft_strncmp(line, "F", 1) == 0)
        parse->floor = red << 16 | green << 8 | blue;
    else if (ft_strncmp(line, "C", 1) == 0)
        parse->ceiling = red << 16 | green << 8 | blue;
}
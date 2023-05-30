/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-fil <fel-fil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 20:41:00 by nloutfi           #+#    #+#             */
/*   Updated: 2023/05/30 15:50:07 by fel-fil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void    check_chars(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] != '1'  && map[i][j] != '0' && map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'E' \
               && map[i][j] != 'W' && !ft_isspace(map[i][j]) && map[i][j] != '2')
               {
                     printf("map[%d][%d] = %c\n",i, j,  map[i][j]);
                     errors("Invalid character in map");
               }
                // errors("Invalid character in map");
            j++;
        }
        i++;
    }
}


void check_player(t_parse *parse)
{
    int i;
    int j;
    
    i = 0;
    while (parse->map[i])
    {
        j = 0;
        while (parse->map[i][j])
        {
            if (parse->map[i][j] == 'N' || parse->map[i][j] == 'S' || parse->map[i][j] == 'E' 
                || parse->map[i][j] == 'W')
                {
                    parse->player++;
                    parse->player_x = j;
                    parse->player_y = i;
                    parse->player_dir = parse->map[i][j];
                    parse->map[i][j] = '0';
                }
            j++;
        }
        i++;
    }
	printf("%d\n", parse->player);
    if (parse->player != 1)
        errors("Invalid player");
}

void    check_borders(t_parse *parse)
{
    int i;
    int j;

    j = 0;
    while (parse->map[0][j])
    {
        if (parse->map[0][j] != '1' && !ft_isspace(parse->map[0][j]) && parse->map[0][j] != '2')
            errors("Invalid map first line");
        j++;
    }
    i = parse->map_height - 1;
    j = 0;
    while (parse->map[i][j])
    {
        if (parse->map[i][j] != '1' && !ft_isspace(parse->map[i][j]) && parse->map[i][j] != '2')
            errors("Invalid map last line");
        j++;
    }
}

void    check_zero(t_parse *parse)
{
    int i;
    int j;

    i = 0;
    while (parse->map[i])
    {
        j = 0;
        while (parse->map[i][j])
        {
            if (parse->map[i][j] == '0' || parse->map[i][j] == 'N'|| parse->map[i][j] == 'S' || parse->map[i][j] == 'E' 
                || parse->map[i][j] == 'W')
            {
                if (!parse->map[i][j - 1] || !parse->map[i][j + 1] || !parse->map[i - 1][j] || !parse->map[i + 1][j])
                    errors("Invalid map");
                if (parse->map[i][j - 1] == '2' || parse->map[i][j + 1] == '2' || parse->map[i - 1][j] == '2' || parse->map[i + 1][j] == '2')
                    errors("Invalid map");
                if (ft_isspace(parse->map[i][j - 1]) || ft_isspace(parse->map[i][j + 1]) || ft_isspace(parse->map[i - 1][j]) || ft_isspace(parse->map[i + 1][j]))
                    errors("Invalid map");
            }
            j++;
        }
        i++;
    }
}


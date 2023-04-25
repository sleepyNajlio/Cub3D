/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 20:41:00 by nloutfi           #+#    #+#             */
/*   Updated: 2023/04/25 12:32:13 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
            if (map[i][j] != '1' && !ft_isspace(map[i][j]) && map[i][j] != '0'
               && map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'E'
               && map[i][j] != 'W')
                errors("Invalid character in map");
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
                }
            j++;
        }
        i++;
    }
    if (parse->player != 1)
        errors("Invalid player");
}

void    check_borders(t_parse *parse)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while (parse->map[0][j])
    {
        if (parse->map[0][j] != '1' && !ft_isspace(parse->map[0][j]))
            errors("Invalid map first line");
        j++;
    }
    // while (i < parse->map_height - 2)
    // {
    //     j = 0;
    //     while (ft_isspace(parse->map[i][j]))
    //         j++;
    //     if (parse->map[i][j] != '1')
    //         errors("Invalid map side 1");
    //     j = ft_strlen(parse->map[i]) - 1;
    //     // printf("j = %c\n", parse->map[i][j]);
    //     // printf("i = %d\n", i);
    //     while (ft_isspace(parse->map[i][j]))
    //         j--;
    //     if (parse->map[i][j] != '1')
    //         errors("Invalid map side 2");
    //     i++;
    // }
    i = parse->map_height - 1;
    j = 0;
    while (parse->map[i][j])
    {
        if (parse->map[i][j] != '1' && !ft_isspace(parse->map[i][j]))
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
            if (parse->map[i][j] == '0')
            {
                if (!parse->map[i][j - 1] || !parse->map[i][j + 1] || !parse->map[i - 1][j] || !parse->map[i + 1][j])
                    errors("Invalid map (zero)");
                if (parse->map[i][j - 1] == ' ' || parse->map[i][j + 1] == ' ' || parse->map[i - 1][j] == ' ' || parse->map[i + 1][j] == ' ')
                    errors("Invalid map (zero)");
            }
            j++;
        }
        i++;
    }
}


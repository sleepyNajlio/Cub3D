/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 20:41:00 by nloutfi           #+#    #+#             */
/*   Updated: 2023/04/22 20:51:25 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
        errors("Error: Invalid player position");
}

void    check_map_walls(t_parse *parse)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (parse->map[i][i])
    {
        if (parse->map[i][j] != '1' && parse->map[i][j] != ' ' && parse->map[i][j] != '\t')) 
            errors("Error: Invalid map");
        j++;
    }
}

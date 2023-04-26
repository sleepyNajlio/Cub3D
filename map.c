/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 00:52:40 by nloutfi           #+#    #+#             */
/*   Updated: 2023/04/26 06:48:08 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int is_map_el(char *line)
{
    int i;

    i = 0;
    while (line[i] == ' ' || line[i] == '\t')
        i++;
    if (line[i] == '1' || line[i] == '0')
        return (1);
    else
        return (0);
}

int map_height(char **file, int i)
{
    int height;

    height = 0;
    while (file[i])
    {
        height++;
        i++;
    }
    return (height);
}

int map_width(char **map)
{
    int i;
    int width;

    i = 0;
    width = 0;
    while (map[i])
    {
        if (ft_strlen(map[i]) > width)
            width = ft_strlen(map[i]);
        i++;
    }
    return (width);
}

void    printf_map(char **map)
{
    int i;

    i = 0;
    while (map[i])
    {
        printf("%s\n", map[i]);
        i++;
    }
}

void check_map(t_parse *parse)
{
    check_chars(parse->map);
    check_borders(parse);
    check_zero(parse);
    check_player(parse);
}

void    parse_map(t_parse *parse, char **file)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (!is_map_el(file[i]))
        i++;
    parse->map_height = map_height(file, i);
    parse->map = (char **)malloc(sizeof(char *) * parse->map_height + 1);
    while (file[i])
    {
        parse->map[j] = ft_strdup(file[i]);
        j++;
        i++;
    }
    parse->map[j] = NULL;
    parse->map_width = map_width(parse->map);
    check_map(parse);
    printf_map(parse->map);
}
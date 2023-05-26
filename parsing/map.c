/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 00:52:40 by nloutfi           #+#    #+#             */
/*   Updated: 2023/05/26 08:50:08 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int is_map_el(char *line)
{
    int i;

    i = 0;
    if (!line)
        return (2);
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

int map_width(char **map, int i)
{
    int width;

    width = 0;
    while (map[i])
    {
        if (ft_strlen(map[i]) > width)
            width = ft_strlen(map[i]);
        i++;
    }
    return (width);
}

void    printf_map(t_parse *parse)
{
    int i;

    i = 0;
    while (parse->map[i])
    {
        printf("%s\n", parse->map[i]);
        i++;
    }
    printf("height: %d width: %d\n", parse->map_height, parse->map_width);
}

void check_map(t_parse *parse)
{
    check_chars(parse->map);
    check_borders(parse);
    check_zero(parse);
    check_player(parse);
    if (parse->map_scale < 0)
        errors("Map too big");
}

char *fill_map_line(char *line, int width)
{
    int i;
    char *map_line;

    i = 0;
    map_line = malloc(sizeof(char) * width + 1);
    while(i < width)
    {
        if (line[i] && !ft_isspace(line[i]))
            map_line[i] = line[i];
        else
            map_line[i] = '2';
        i++;
    }
    map_line[i] = '\0';
    return (map_line);
}

int min(int a, int b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

void    parse_map(t_parse *parse, char **file)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (!is_map_el(file[i]))
        i++;
    if (is_map_el(file[i]) == 2)
        errors("map Incomplete");
    parse->map_height = map_height(file, i);
    parse->map_width = map_width(file, i);
    parse->map_scale = min(SCREEN_HEIGHT / parse->map_height, SCREEN_WIDTH / parse->map_width);
    parse->map = (char **)malloc(sizeof(char *) * parse->map_height + 1);
    while (file[i])
    {
        parse->map[j] = fill_map_line(file[i], parse->map_width);
        j++;
        i++;
    }
    parse->map[j] = NULL;
    printf_map(parse);
    check_map(parse);
}
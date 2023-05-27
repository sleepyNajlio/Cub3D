/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 00:52:40 by nloutfi           #+#    #+#             */
/*   Updated: 2023/05/27 13:29:30 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int is_map_el(char *line)
{
    int i;

    i = 0;
    if (!line)
        return (2);
    while (ft_isspace(line[i]))
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
    while (file[i] && is_map_el(file[i]) == 1)
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
    while (map[i] && is_map_el(map[i]) == 1)
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
    if (parse->cell_size < 0)
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
        if (line[i] && !ft_isspace(line[i]) && line[i] )
            map_line[i] = line[i];
        else
            map_line[i] = '2';
        i++;
    }
    map_line[i] = '\0';
    // printf("%s\n", map_line);
    return (map_line);
}

void fill_map(char **map, char **file, int i, int width)
{
    int j;
    int k;

    k = 0;
    while (file[i] && is_map_el(file[i]) == 1)
    {
        j = 0;
        map[k] = malloc(sizeof(char) * width + 1);
        while (file[i][j])
        {
            map[k][j] = file[i][j];
            j++;
        }
        while (j < width)
        {
            map[k][j] = '2';
            j++;
        }
        map[k][j] = '\0';
        k++;
        i++;
    }
    map[k] = NULL;
}

int count_spaces(char **map)
{
    int i;
    int j;
    int spaces;
    int res;

    i = 0;
    spaces = 0;
    res = 1;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (ft_isspace(map[i][j]))
                spaces++;
            j++;
        }
        if (res > spaces)
            res = spaces;
        i++;
    }
    return (spaces);
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
    parse->cell_size = min(SCREEN_HEIGHT / parse->map_height, SCREEN_WIDTH / parse->map_width);
    parse->map = (char **)malloc(sizeof(char *) * parse->map_height + 1);
    fill_map(parse->map, file, i, parse->map_width);
    // printf("height: %d width: %d\n", parse->map_height, parse->map_width);
    // printf_map(parse);
    check_map(parse);
    // correct_map(parse);
}


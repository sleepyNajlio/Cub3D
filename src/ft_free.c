/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 06:59:33 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/13 10:12:23 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tab(char **file)
{
	int	i;

	i = 0;
	while (file && file[i])
	{
		free(file[i]);
		i++;
	}
	free(file);
}

void	free_parse(t_parse *parse)
{
	if (parse->no)
		free(parse->no);
	if (parse->so)
		free(parse->so);
	if (parse->we)
		free(parse->we);
	if (parse->ea)
		free(parse->ea);
	free_tab(parse->map);
	free(parse);
}

// void	free_tex(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	while (data->text[i])
// 	{
// 		if (text[i]->img)
// 		{
// 			mlx_destroy_image(text[i]->mlx, text[i]->img);
// 			free(text[i]->img);
// 		}
// 		free(text[i]);
// 		i++;
// 	}
// }

void	free_data(t_data *data)
{
	if (data->mlx)
		free(data->mlx);
	if (data->img)
	{
		mlx_destroy_image(data->mlx, data->img->img);
		free(data->img);
	}
	if (data->win)
	{
		mlx_destroy_image(data->mlx, data->img);
		free(data->img);
	}
	free_parse(data->parse);
	if (data->player)
		free(data->player);
	if (data->rays)
		free(data->rays);
	free(data);
}

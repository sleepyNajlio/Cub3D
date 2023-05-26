/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-fil <fel-fil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:47:05 by fel-fil           #+#    #+#             */
/*   Updated: 2023/05/25 06:41:41 by fel-fil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "../cub3d.h"

void	game_init(t_data *data);
void	rot_left(t_data *data);
void	rot_right(t_data *data);
int		draw_again(t_data *data);
double	standardized_range(double angle);
int		draw_again(t_data *data);
int		check_wall(t_parse *parse, double x, double y);
void	raycasting(t_data *data);
void	inc_ray(t_data *data, int i);
void	stop_inc(t_data *data, int i);
void	delta_x_y(t_data *data, int i);
void	x_y_first_inter(t_data *data, int i);
void	facing_dir(t_data *data, int i);

#endif
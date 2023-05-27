/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:47:05 by fel-fil           #+#    #+#             */
/*   Updated: 2023/05/27 13:56:45 by nloutfi          ###   ########.fr       */
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
void	raycasting(t_data *data);
void	inc_ray(t_data *data, int i);
void	stop_inc(t_data *data, int i);
void	delta_x_y(t_data *data, int i);
void	x_y_first_inter(t_data *data, int i);
void	facing_dir(t_data *data, int i);
int		has_wall_at(t_data *data, double x, double y);

#endif
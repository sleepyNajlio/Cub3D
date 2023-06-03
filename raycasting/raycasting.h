/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-fil <fel-fil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:47:05 by fel-fil           #+#    #+#             */
/*   Updated: 2023/06/03 17:34:12 by fel-fil          ###   ########.fr       */
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
int		has_wall_at(t_data *data, double x, double y);
void	init_textures(t_data	*data);
void	init_rays(t_data *data);
void	init_player(t_player *player, t_parse *parse);
int		has_wall_at(t_data *data, double x, double y);
double	dist_ray(double x1, double y1, double x2, double y2);
void	ray_dire(t_data *data, int i);
void	first_inter_h(t_data *data, int i);
void	x_y_step_h(t_data *data, int i);
void	stop_inc(t_data *data, int i);
void	inc_ray(t_data *data, int i);
void	inc_ray_v(t_data *data, int i);
void	stop_inc_v(t_data *data, int i);
void	x_y_step_v(t_data *data, int i);
void	first_inter_v(t_data *data, int i);
void	ray_dir_v(t_data *data, int i);
void	hor_dis(t_data *data, int i, double h_dis);
void	ver_dis(t_data *data, int i, double v_dis);

#endif
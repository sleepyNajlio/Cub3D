/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:05:49 by nloutfi           #+#    #+#             */
/*   Updated: 2023/05/27 10:15:00 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "mlx/mlx.h"
# include "parsing/parse.h"
# include <limits.h>

# define CELL_SIZE 64
# define P_SPEED 10
# define P_ROT_SPEED 0.1
# define MINIMAP_SCALE_FACTOR 1

# define BLUE 0x0000FF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define GRAY 0x808080

# define KEY_ESC 53
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_player
{
	double	x;
	double	y;
	double	angle;
}	t_player;

typedef struct s_ray
{
	double	fov_angle;
	double	num_rays;
	double	ray_angle;
	double	distance;
	int		isfacingdown;
	int		isfacingup;
	int		isfacingleft;
	int		isfacingright;
	double	yintercept;
	double	xintercept;
	double	ystep;
	double	xstep;
	double	nxt_horz_x_inter;
	double	nxt_ver_x_inter;
	double	nxt_horz_y_inter;
	double	nxt_ver_y_inter;
	int		found_h_wall_hit;
	int		found_v_wall_hit;
	double	hor_wall_hit_x;
	double	ver_wall_hit_x;
	double	hor_wall_hit_y;
	double	ver_wall_hit_y;
	double	wall_x;
	double	wall_y;
	int		was_hit_vertical;
	double	corr_wall_dis;
	double	project_plan_dis;
	double	wall_strip_height;
}	t_ray;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_parse		*parse;
	t_player	*player;
	t_ray		*rays;
	int			win_w;
	int			win_h;
}	t_data;

// draw_2d
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	draw_square(t_img *img, double x, double y, double size, int color);
void	main_draw(t_data *data);
void	game_init(t_data *data);
void	draw_line(t_img *img, int x0, int y0, int x1, int y1, int color);
void	draw_circle(t_img *img, int x, int y, int radius, int color);
void	render3dProjection(t_data *data, int i);

// hooks
int		key_hook(int keycode, t_data *data);

#endif
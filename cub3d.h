/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:05:49 by nloutfi           #+#    #+#             */
/*   Updated: 2023/05/08 21:39:02 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "mlx/mlx.h"
# include "parsing/parse.h"

# define CELL_SIZE 32
# define FOV_ANGLE (60 * (PI / 180))
# define P_SPEED 14
# define P_ROT_SPEED 0.1

#define BLUE 0x0000FF
#define RED 0xFF0000
#define GREEN 0x00FF00
#define WHITE 0xFFFFFF
#define BLACK 0x000000

#define KEY_ESC 53
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_W 13
#define KEY_LEFT 123
#define KEY_RIGHT 124
#define KEY_DOWN 125
#define KEY_UP 126

typedef struct s_img 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_img;

typedef struct s_player
{
	float x;
	float y;
	float angle;
} t_player;

typedef struct s_data
{
    void    *mlx;
    void    *win;
    t_img	*img;
	t_parse *parse;
	t_player *player;
}              t_data;

// draw_2d
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void 	draw_square(t_img *img, int x, int y, int size, int color);
void	draw_map(t_data *data);

// hooks
int	key_hook(int keycode, t_data *data);


#endif
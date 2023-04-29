/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:05:49 by nloutfi           #+#    #+#             */
/*   Updated: 2023/04/29 22:22:13 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "mlx/mlx.h"
# include "parsing/parse.h"

# define CELL_SIZE 32

#define BLUE 0x0000FF
#define RED 0xFF0000
#define GREEN 0x00FF00
#define WHITE 0xFFFFFF

#define KEY_ESC 53
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2


typedef struct s_img 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_img;

typedef struct s_data
{
    void    *mlx;
    void    *win;
    t_img	*img;
	t_parse *parse;
    
}              t_data;

#endif
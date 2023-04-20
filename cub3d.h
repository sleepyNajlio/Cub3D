/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 04:30:59 by nloutfi           #+#    #+#             */
/*   Updated: 2023/04/20 23:58:54 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <math.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include "get_next_line.h"

typedef struct s_parse {
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int 	floor;
	int 	ceiling;
	char 	**map;
	
}	t_parse;

typedef struct s_data {
	char 	*file;
	int 	no;
	int 	so;
	int 	we;
	int 	ea;
	int 	floor;
	int 	ceiling;
	int		invalid;
}	t_data;

// libft_tools
int ft_strcmp(char *s1, char *s2);
char *ft_strdup(char *s);
char	*ft_substr(char *s, int start, int len);

// map_errors
void first_check(int ac, char **av);


// parsing
t_parse	*parsing(char *path);


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 04:30:59 by nloutfi           #+#    #+#             */
/*   Updated: 2023/04/22 13:12:41 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <math.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

typedef struct s_parse {
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int 	floor;
	int 	ceiling;
	int		tex;
	char 	**map;
}	t_parse;


// libft_tools
int 	ft_strncmp(char *s1, char *s2, int n);
char 	*ft_strdup(char *s);
char	*ft_substr(char *s, int start, int len);
int 	ft_strlen(char *s);
char	**ft_split(char *line, char c);
int 	ft_isdigit(char *str);
int 	ft_atoi(char *str);

// map_errors
void first_check(int ac, char **av);
void	errors(char *str);


// parsing
t_parse	*parsing(char *path);
void	print_tab(char **tab);

// tools0
char	*remove_spc(char *line);
char	*remove_nl(char *line);


// identifiers
void	identifiers(t_parse *parse, char **file);
int 	is_iden(char *line, t_parse *parse);
int     is_empty_line(char *line);
int     is_map_line(char *line);
void    check_identifiers(t_parse *parse);

// iden_tools
void	get_color(char *line, t_parse *parse);
char	**check_color(char *line);
void    get_tex(char *line, t_parse *parse);

#endif
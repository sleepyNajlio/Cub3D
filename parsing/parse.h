/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 04:30:59 by nloutfi           #+#    #+#             */
/*   Updated: 2023/04/26 12:13:28 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include "get_next_line.h"


typedef struct s_parse {
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int 	floor;
	int 	ceiling;
	int		tex;
	char 	**map;
	int 	map_width;
	int 	map_height;
	int 	player;
	int 	player_x;
	int 	player_y;
}	t_parse;


// libft_tools
int 	ft_strncmp(char *s1, char *s2, int n);
char 	*ft_strdup(char *s);
char	*ft_substr(char *s, int start, int len);
int 	ft_strlen(char *s);
char	**ft_split(char *line, char c);
int 	ft_isdigit(char *str);
int 	ft_atoi(char *str);
int 	ft_isspace(char c);

// errors
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

// map
void    parse_map(t_parse *parse, char **file);
void    check_borders(t_parse *parse);
void 	check_player(t_parse *parse);
void    check_chars(char **map);
void    check_zero(t_parse *parse);

// ft_free
void free_tab(char **file);
void free_struct(t_parse *parse);

#endif
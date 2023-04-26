/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-fil <fel-fil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:29:13 by fel-fil           #+#    #+#             */
/*   Updated: 2022/02/22 16:13:13 by fel-fil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include<stdlib.h>
# include<stdio.h>
# include <unistd.h>
# include<string.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char	*s2);
int		ft_strchr(char *s);
char	*select_left(char *s);
char	*select_right(char *s);
char	*read_ln(int fd, char *str, char *buf);
int		ft_strlen(char *s);

#endif
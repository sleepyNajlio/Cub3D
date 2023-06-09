/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 06:59:33 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/03 18:15:02 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	free_tab(char **file)
{
	int	i;

	i = 0;
	while (file && file[i])
	{
		free(file[i]);
		i++;
	}
	free(file);
}

void	free_struct(t_parse *parse)
{
	if (parse->no)
		free(parse->no);
	if (parse->so)
		free(parse->so);
	if (parse->we)
		free(parse->we);
	if (parse->ea)
		free(parse->ea);
	free_tab(parse->map);
	free(parse);
}

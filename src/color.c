/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:39:49 by matde-ol          #+#    #+#             */
/*   Updated: 2024/01/18 19:27:18 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color_red(t_coord **xyz, int y, int x)
{
	char	tmp[3];
	int		i;
	int		j;

	j = 0;
	while (xyz[y][x].color[j] != '\0')
	{
		i = 0;
		while (i < 2)
		{
			tmp[i] = xyz[y][x].color[j];
			i++;
			j++;
		}
		tmp[i] = '\0';
		if (j < 3)
			xyz[y][x].red = ft_atoi_hexa(tmp);
		else if (j > 3 && j < 5)
			xyz[y][x].green = ft_atoi_hexa(tmp);
		else
			xyz[y][x].blue = ft_atoi_hexa(tmp);
	}
}

void	color_green(t_coord **xyz, int y, int x)
{
	char	tmp[3];
	int		i;
	int		j;

	j = 0;
	xyz[y][x].red = ft_atoi_hexa("00");
	while (xyz[y][x].color[j] != '\0')
	{
		i = 0;
		while (i < 2)
		{
			tmp[i] = xyz[y][x].color[j];
			i++;
			j++;
		}
		tmp[i] = '\0';
		if (j < 3)
			xyz[y][x].green = ft_atoi_hexa(tmp);
		else
			xyz[y][x].blue = ft_atoi_hexa(tmp);
	}
}

void	color_blue(t_coord **xyz, int y, int x)
{
	char	tmp[3];
	int		i;
	int		j;

	j = 0;
	xyz[y][x].red = ft_atoi_hexa("00");
	xyz[y][x].green = ft_atoi_hexa("00");
	while (xyz[y][x].color[j] != '\0')
	{
		i = 0;
		while (i < 2)
		{
			tmp[i] = xyz[y][x].color[j];
			i++;
			j++;
		}
		tmp[i] = '\0';
		xyz[y][x].blue = ft_atoi_hexa(tmp);
	}
}

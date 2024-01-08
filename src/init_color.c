/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:14:18 by matde-ol          #+#    #+#             */
/*   Updated: 2024/01/08 15:23:04 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	color_shift(t_coord **xyz, int x, int y)
{
	if (xyz[y][x].color != NULL)
	{
		xyz[y][x].all_color = (xyz[y][x].red << 16);
		xyz[y][x].all_color |= (xyz[y][x].green << 8);
		xyz[y][x].all_color |= (xyz[y][x].blue << 0);
	}
	else
	{
		xyz[y][x].all_color = (255 << 16);
		xyz[y][x].all_color |= (255 << 8);
		xyz[y][x].all_color |= (255 << 0);
	}
}

static void	color_char_to_int(t_coord **xyz, int y, int x)
{
	int		i;
	char	tmp[3];

	i = 0;
	if (xyz[y][x].color != NULL)
	{
		while (xyz[y][x].color[i] != '\0')
		{
			tmp[0] = xyz[y][x].color[i];
			tmp[1] = xyz[y][x].color[i + 1];
			tmp[2] = '\0';
			if (i < 2)
				xyz[y][x].red = ft_atoi_hexa(tmp);
			else if (i < 4)
				xyz[y][x].green = ft_atoi_hexa(tmp);
			else if (i < 6)
				xyz[y][x].blue = ft_atoi_hexa(tmp);
			i += 2;
		}
		
	}
	color_shift(xyz, x, y);
}

static int	pos_color(t_coord **xyz, int x, int y)
{
	int	i;

	i = 0;
	while (xyz[y][x].all[i] != '\0')
	{
		if (xyz[y][x].all[i] == 'x')
			return (i + 1);
		i++;
	}
	return (0);
}
static int	color_add_convert(t_coord **xyz, int y, int x)
{
	int		len_all;
	int		i_color;
	int		len;
	
	while (xyz[y][x].all != NULL)
	{
		len_all = ft_strlen(xyz[y][x].all);
		i_color = pos_color(xyz, x, y);
		if (i_color == 0)
			xyz[y][x].color = NULL;
		else
		{
			len = len_all - i_color;
			xyz[y][x].color = ft_substr(xyz[y][x].all, i_color, len);
			if (xyz[y][x].color == NULL)
			{
				return (-1);
			}
		}	
		color_char_to_int(xyz, y, x);
		x++;
	}
	return (0);
}

void	init_color(t_coord **xyz, int y)
{
	int		x;

	while (xyz[y] != NULL)
	{
		x = 0;
		if (color_add_convert(xyz, y, x) == -1)
		{
			clear_xyz(xyz);
			return ;
		}
		y++;
	}
}

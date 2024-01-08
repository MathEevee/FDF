/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_ft_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 10:45:44 by matde-ol          #+#    #+#             */
/*   Updated: 2024/01/08 10:06:02 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_bits(t_coord **xyz, int y, int x)
{
	int	i;

	i = 31;
	while (i >= 0)
	{
		if (xyz[y][x].all_color >> i & 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i--;
	}
}

void	print_all(t_coord **xyz)
{
	int	y;
	int	x;
	int	j;
	int	k;

	y = count_y(xyz);
	x = count_x(xyz);
	k = 0;
	while (k <= y)
	{
		j = 0;
		while (j <= x)
		{
			ft_printf("[all : %s] ", xyz[k][j].all);
			ft_printf("(z : %d)", xyz[k][j].z);
			ft_printf("!color : %s! ", xyz[k][j].color);
			ft_printf("@red : %d@", xyz[k][j].red);
			ft_printf("/green : %d/ ", xyz[k][j].green);
			ft_printf(".blue : %d. ", xyz[k][j].blue);
			ft_printf("$all_color : %d$", xyz[k][j].all_color);
			ft_printf("|");
			print_bits(xyz, k, j);
			ft_printf("|");
			j++;
		}
		ft_printf("\nnew line\n");
		k++;
	}
	ft_printf("-y : %d x : %d-", y, x);
}

/*	nx = (1024 / count_x(xyz) / 4);
	ny = (600 / count_y(xyz) / 4);
	posx = nx * x - (ny * y);
	posy = ny * y + (xyz[y][x].z * y);*/

/*void	pixel_to_window(t_vars *vars, int y, int x, t_coord **xyz)
{
	int		nx;
	int		ny;
	int		posx;
	int		posy;

	nx = (1024 / count_x(xyz) / 4);
	ny = (600 / count_y(xyz) / 4);
	posx = nx * x - (ny * y);
	posy = ny * y - (xyz[y][x].z * 2) + (nx * x);
	mlx_pixel_put(vars->mlx, vars->win, (500 + posx), (100 + posy), xyz[y][x].all_color);
*/
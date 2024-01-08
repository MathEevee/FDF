/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:50:29 by matde-ol          #+#    #+#             */
/*   Updated: 2024/01/08 20:01:56 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	close_window(int keycode, void *vars)
{
	t_vars *v;

	v = (t_vars *) vars;
	if (keycode == 41)
	{
		mlx_loop_end(v->mlx);
		mlx_destroy_image(v->mlx, v->img);
		mlx_destroy_window(v->mlx, v->win);
		mlx_destroy_display(v->mlx);
		exit(0);
	}
	return (0);
}


static void	add_pixel(t_coord **xyz, t_vars *vars)
{
	int	y;
	int	x;
	
	y = 0;
	while (xyz[y] != NULL)
	{
		x = 0;
		while (xyz[y][x].all != NULL)
		{
			draw_line(vars, y, x, xyz);
			//pixel_to_window(vars, y, x, xyz);
			x++;
			ft_printf("x add pixel : %d\n", x);
		}
		y++;
		ft_printf(" add pixel : %d\n", x);
	}
}

void	init_window(t_coord **xyz)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "FDF");
	vars.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	add_pixel(xyz, &vars);
	mlx_on_event(vars.mlx, vars.win, 0, close_window, &vars);
	mlx_loop(vars.mlx);
	clear_xyz(xyz);
}
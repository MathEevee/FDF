/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:50:29 by matde-ol          #+#    #+#             */
/*   Updated: 2024/01/21 18:30:18 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	cross_close(int keycode, void *vars)
{
	t_vars	*v;

	v = (t_vars *) vars;
	if (keycode == 0)
	{
		mlx_loop_end(v->mlx);
		mlx_destroy_image(v->mlx, v->img);
		mlx_destroy_window(v->mlx, v->win);
		mlx_destroy_display(v->mlx);
		exit(0);
	}
	return (0);
}

static int	close_window(int keycode, void *vars)
{
	t_vars	*v;

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
	t_calc	*data;

	data = malloc(sizeof(t_calc));
	if (data == NULL)
	{
		clear_xyz(xyz, 1);
		mlx_destroy_display(vars->mlx);
		mlx_destroy_window(vars->mlx, vars->win);
		msg_error();
		exit(0);
	}
	calc_data(xyz, data);
	line_x_all(xyz, data, vars);
	line_y(xyz, vars, data);
	clear_end(xyz, data);
}

void	init_window(t_coord **xyz)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return ;
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "FDF");
	if (vars.win == NULL)
	{
		mlx_destroy_display(vars.mlx);
		return ;
	}
	vars.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	if (vars.img == NULL)
	{
		mlx_destroy_display(vars.mlx);
		mlx_destroy_window(vars.mlx, vars.win);
		return ;
	}
	add_pixel(xyz, &vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	mlx_on_event(vars.mlx, vars.win, 0, close_window, &vars);
	mlx_on_event(vars.mlx, vars.win, 5, cross_close, &vars);
	mlx_loop(vars.mlx);
}

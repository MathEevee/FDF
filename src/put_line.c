/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:48:25 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/04 11:14:41 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line_x_all(t_coord **xyz, t_calc *data, t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->nbr_y)
	{
		x = 0;
		while (x < data->nbr_x - 1)
		{
			calc_data(xyz, data);
			data->col = xyz[y][x].all_color;
			data->z1 = xyz[y][x].z;
			data->z2 = xyz[y][x + 1].z;
			line_x(y, x, data, vars);
			x++;
		}
		y++;
	}
}

static void	put_back_line(int y, int x, t_calc *data, t_vars *vars)
{
	float	i;
	float	c;

	calc_coord(y, x, data);
	i = data->y1;
	c = ((data->x2 - data->x1) / ((data->y2) - i));
	if (((data->y2) - i) == 0)
		const_x(data, vars, i);
	else if (c < 0 && ((data->y2) - i) < 0)
		coef_n_diff_y_n(data, vars, i, c);
	else if (c < 0 && ((data->y2) - i) > 0)
		coef_n_diff_y_p(data, vars, i, c);
	else if (c > 0 && ((data->y2) - i) < 0)
		coef_p_diff_y_n(data, vars, i, c);
	else if (c > 0 && ((data->y2) - i) > 0)
		coef_p_diff_y_p(data, vars, i, c);
	else
		const_y(data, vars, i);
}

void	line_y(t_coord **xyz, t_vars *vars, t_calc *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->nbr_x)
	{
		y = data->nbr_y - 2;
		while (y >= 0)
		{
			data->col = xyz[y][x].all_color;
			data->z1 = xyz[y][x].z;
			data->z2 = xyz[y + 1][x].z;
			put_back_line(y, x, data, vars);
			y--;
		}
		x++;
	}
}

void	line_x(int y, int x, t_calc *data, t_vars *vars)
{
	float	i;
	float	c;

	calc_coord(y, x, data);
	i = data->y1;
	c = ((data->y2) - (data->y1)) / (data->x2 - data->x1);
	if (c < 0 && (data->x2 - data->x1) < 0)
		coef_n_diff_x_n(data, vars, i, c);
	else if (c < 0 && (data->x2 - data->x1) > 0)
		coef_n_diff_x_p(data, vars, i, c);
	else if (c > 0 && (data->x2 - data->x1) < 0)
		coef_p_diff_x_n(data, vars, i, c);
	else if (c > 0 && (data->x2 - data->x1) > 0)
		coef_p_diff_x_p(data, vars, i, c);
	else
		const_x(data, vars, i);
}

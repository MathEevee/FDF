/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:05:19 by matde-ol          #+#    #+#             */
/*   Updated: 2024/01/19 11:59:13 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	c_n_x_n(t_calc *data, t_vars *vars, float i, float c)
{
	float	r;
	float	new_coef;

	new_coef = c;
	if (c >= 1 || c <= -1)
		new_coef = (data->x1 - data->x2) / ((data->y1) - (data->y2));
	r = data->x1;
	while (r > data->x2)
	{
		if (c > -1)
		{
			r--;
			i += new_coef;
		}
		else
		{
			r += new_coef;
			i++;
		}
		mlx_set_image_pixel(vars->mlx,
			vars->img, ft_roundf(r), ft_roundf(i), data->col);
	}
}

void	c_n_x_p(t_calc *data, t_vars *vars, float i, float c)
{
	float	r;
	float	new_coef;

	new_coef = c;
	if (c >= 1 || c <= -1)
		new_coef = (data->x1 - data->x2) / ((data->y1) - (data->y2));
	r = data->x1;
	while (r <= data->x2)
	{
		if (c > -1)
		{
			r++;
			i += new_coef;
		}
		else
		{
			i--;
			r -= new_coef;
		}
		mlx_set_image_pixel(vars->mlx,
			vars->img, ft_roundf(r), ft_roundf(i), data->col);
	}
}

void	c_p_x_n(t_calc *data, t_vars *vars, float i, float c)
{
	float	r;
	float	new_coef;

	new_coef = c;
	if (c >= 1 || c <= -1)
		new_coef = (data->x1 - data->x2) / ((data->y1) - (data->y2));
	r = data->x1;
	while (r >= data->x2)
	{
		if (c > 1)
		{
			i--;
			r -= new_coef;
		}
		else
		{
			r--;
			i -= new_coef;
		}
		mlx_set_image_pixel(vars->mlx,
			vars->img, ft_roundf(r), ft_roundf(i), data->col);
	}
}

void	c_p_x_p(t_calc *data, t_vars *vars, float i, float c)
{
	float	r;
	float	new_coef;

	new_coef = c;
	if (c >= 1 || c <= -1)
		new_coef = (data->x1 - data->x2) / ((data->y1) - (data->y2));
	r = data->x1;
	while (r <= data->x2)
	{
		if (c > 1)
		{
			r += new_coef;
			i++;
		}
		else
		{
			r++;
			i += new_coef;
		}
		mlx_set_image_pixel(vars->mlx,
			vars->img, ft_roundf(r), ft_roundf(i), data->col);
	}
}

void	const_x(t_calc *data, t_vars *vars, float i)
{
	float	r;

	r = data->x1;
	if ((data->x2 - data->x1) < 0)
	{
		while (r >= data->x2)
		{
			r--;
			mlx_set_image_pixel(vars->mlx, vars->img,
				ft_roundf(r), ft_roundf(i), data->col);
		}
	}
	else
	{
		while (r <= data->x2)
		{
			r++;
			mlx_set_image_pixel(vars->mlx, vars->img,
				ft_roundf(r), ft_roundf(i), data->col);
		}
	}
}

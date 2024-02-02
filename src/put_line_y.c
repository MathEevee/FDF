/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line_y.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:05:19 by matde-ol          #+#    #+#             */
/*   Updated: 2024/01/19 11:53:23 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	c_n_y_n(t_calc *data, t_vars *vars, float i, float c)
{
	float	r;
	float	new_coef;

	new_coef = c;
	if (c >= 1 || c <= -1)
		new_coef = ((data->y1) - (data->y2)) / (data->x1 - data->x2);
	r = data->x1;
	while (i >= data->y2)
	{
		if (c < -1)
		{
			i += new_coef;
			r--;
		}
		else
		{
			r += new_coef;
			i--;
		}
		mlx_set_image_pixel(vars->mlx,
			vars->img, ft_roundf(r), ft_roundf(i), data->col);
	}
}

void	c_n_y_p(t_calc *data, t_vars *vars, float i, float c)
{
	float	r;
	float	new_coef;

	new_coef = -c;
	if (c >= 1 || c <= -1)
		new_coef = ((data->y1) - (data->y2)) / (data->x1 - data->x2);
	r = data->x1;
	while (i < data->y2)
	{
		if (c < 1)
		{
			i++;
			r -= new_coef;
		}
		else
		{
			r--;
			i += new_coef;
		}
		mlx_set_image_pixel(vars->mlx,
			vars->img, ft_roundf(r), ft_roundf(i), data->col);
	}
}

void	c_p_y_n(t_calc *data, t_vars *vars, float i, float c)
{
	float	r;
	float	new_coef;

	new_coef = c;
	if (c >= 1 || c <= -1)
		new_coef = (((data->y1 + data->z1) - (data->y2 + data->z2)))
			/ (data->x1 - data->x2);
	r = data->x1;
	while (i > data->y2)
	{
		if (c > 1)
		{
			i--;
			r += new_coef;
		}
		else
		{
			r++;
			i -= new_coef;
		}
		mlx_set_image_pixel(vars->mlx, vars->img,
			ft_roundf(r), ft_roundf(i), data->col);
	}
}

void	c_p_y_p(t_calc *data, t_vars *vars, float i, float c)
{
	float	r;
	float	new_coef;

	new_coef = c;
	if (c >= 1 || c <= -1)
		new_coef = ((data->y1) - (data->y2)) / (data->x1 - data->x2);
	r = data->x1;
	while (i < data->y2)
	{
		if (c < 1)
		{
			r -= new_coef;
			i++;
		}
		else
		{
			i += new_coef;
			r--;
		}
		mlx_set_image_pixel(vars->mlx,
			vars->img, ft_roundf(r), ft_roundf(i), data->col);
	}
}

void	const_y(t_calc *data, t_vars *vars, float i)
{
	float	r;

	r = data->x1;
	if ((data->y2 - data->y1) < 0)
	{
		while (i >= data->y2)
		{
			i--;
			mlx_set_image_pixel(vars->mlx, vars->img,
				ft_roundf(r), ft_roundf(i), data->col);
		}
	}
	else
	{
		while (i <= data->y2)
		{
			i++;
			mlx_set_image_pixel(vars->mlx, vars->img,
				ft_roundf(r), ft_roundf(i), data->col);
		}
	}
}

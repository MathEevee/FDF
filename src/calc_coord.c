/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 10:03:40 by matde-ol          #+#    #+#             */
/*   Updated: 2024/01/21 18:49:38 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calc_data(t_coord **xyz, t_calc *data)
{
	data->nbr_x = count_x(xyz, 0) + 1;
	data->nbr_y = count_y(xyz) + 1;
	if (data->nbr_y < data->nbr_x)
		data->diff = data->nbr_x;
	else
		data->diff = data->nbr_y;
}

void	calc_coord(int y, int x, t_calc *data)
{
	float	v;
	float	u;

	v = ((0.3 * WIDTH) / (data->diff));
	u = ((0.2 * HEIGHT) / (data->diff));
	data->x1 = (WIDTH * 0.4 + data->diff * u / 2) + (v * (x - y));
	data->y1 = (HEIGHT * 0.1) + (u * (x + y)) - (data->z1);
	data->x2 = (WIDTH * 0.4 + data->diff * u / 2) + (v * ((x + 1) - y));
	data->y2 = (HEIGHT * 0.1) + (u * (x + (y + 1))) - (data->z2);
}

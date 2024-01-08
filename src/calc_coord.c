/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 10:03:40 by matde-ol          #+#    #+#             */
/*   Updated: 2024/01/08 20:05:57 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

/*static void	put_line_x(t_vars *vars, int y, int x, t_coord **xyz)
{
	int	a;
	int	x2;
	int	y2;

	a = ()
}*/

void	pixel_to_window(t_vars *vars, int y, int x, t_coord **xyz)
{
	int		nx;
	int		ny;
	int		posx;
	int		posy;

	nx = (1024 / count_x(xyz) / 4);
	ny = (600 / count_y(xyz) / 4);
	posx = (1024 / 2) - (nx * x - (ny * y));
	posy = (600 / 6) + (ny * y - xyz[y][x].z + (nx * x));
	mlx_pixel_put(vars->mlx, vars->win, posx, posy, xyz[y][x].all_color);
	//put_line_x(vars, y, x, xyz);
	//put_line_y(vars, y, x, xyz);
	//put_line(vars,)
}
/*static int	calc_y(int y, t_coord **xyz, int x)
{
	int	y_dist;
	int	y_in_window;
	
	y_dist = (600 / count_x(xyz) / 4);
	y_in_window = (y * y_dist) + (x * y_dist) - (xyz[y][x].z);
	return (y_in_window);
}
static int	calc_x(int x, t_coord **xyz, int y)
{
	int	x_dist;
	int	x_in_window;

	x_dist = (1024 / count_x(xyz) / 4);
	x_in_window = (x * x_dist) + (y * x_dist);
	return (x_in_window);
}*/

void	draw_line(t_vars *vars, int y, int x, t_coord **xyz)
{
	t_bresenham math;

    math.dx = (x + 1) - x;
    math.dy = (y + 1) - y;
    math.x = x;
    math.y = y/* + xyz[y][x].z*/;
    math.d = math.dy / math.dx;
    mlx_pixel_put(vars->mlx, vars->img, math.dx, math.dy, xyz[y][x].all_color);
	ft_printf("test");
    while (math.x <= y + 1)
    {
        if (math.d <= 0)
        {
            math.x += 1;
            mlx_pixel_put(vars->mlx, vars->img, math.dx, math.dy, xyz[y][x].all_color);
            //math.d = math.d + 2 * math.dy - 2 * math.dx;
        }
        else if (math.d > 0)
        {
            math.y -= 1;
            math.x += 1;
            mlx_pixel_put(vars->mlx, vars->img, math.x, math.y, xyz[y][x].all_color);
            //math.d = math.d + 2 * math.dy - 2 * math.dx;
        }

    }
}

/*t_bresenham mathvoid    ft_bresenham(t_vars vars, t_bresenham math)
{
   
}*/
/*

	//int		x1;
	int		x2;
	//int		y1;
	int		y2;
	int		a;
	int		b;

	x1 = x;
	y1 = y;
	x2 = x + 1;
	y2 = y + 1;
	a = (x2 - x) / ((y2 - xyz[y2][x].z) - (y - xyz[y][x].z));
	b = y - (a * x);
	ft_printf("a : %d\n", a);
	ft_printf("b : %d\n", b);
	while (a <= b)
	{
		if (a <= 0)
		{
			a -= 1;
			mlx_pixel_put(vars->mlx, vars->win, a, b, xyz[y][x].all_color);
		}
		else if (a > 0)
		{
			a += 1;
			b += 1;
			mlx_pixel_put(vars->mlx, vars->win, a, b, xyz[y][x].all_color);
		}
	}
*/
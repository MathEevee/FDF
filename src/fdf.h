/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 09:26:25 by matde-ol          #+#    #+#             */
/*   Updated: 2024/01/08 19:56:29 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../Libft/libft.h"
# include "../MacroLibX-master/includes/mlx.h"
# include <fcntl.h>
# define HEIGHT 600
# define WIDTH 1024

typedef struct s_bresenham
{
    int    x1;
    int    x2;
    int    y1;
    int    y2;
    int    dx;
    int    dy;
    int    x;
    int    y;
    int d;
}    t_bresenham;

typedef	struct s_coord
{
	char	*all;
	int		z;
	char	*color;
	int		red;
	int		green;
	int		blue;
	int		all_color;
}				t_coord;

typedef	struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
}			t_vars;

int		check_lst(t_list *lst);
t_coord	**init_tab(t_list *lst);
void	lst_clear_all(t_list *lst);
int		count_split(char **src);
int		count_tab(char const *s, char c);
void	init_color(t_coord **xyz, int y);
void	free_two_tab(int y, t_coord **xyz, char **dest);
void	clear_all_init(t_list *save, t_coord **xyz, int y);
void	lst_clear_all(t_list *lst);
void	init_window(t_coord **xyz);
void	clear_xyz(t_coord **xyz);
int		count_x(t_coord **xyz);
int		count_y(t_coord **xyz);
void	pixel_to_window(t_vars *vars, int y, int x, t_coord **xyz);
void	draw_line(t_vars *vars, int y, int x, t_coord **xyz);


void	print_bits(t_coord **xyz, int y, int x); //a supprime
void	print_all(t_coord **xyz);




#endif

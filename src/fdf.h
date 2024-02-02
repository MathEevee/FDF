/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 09:26:25 by matde-ol          #+#    #+#             */
/*   Updated: 2024/01/21 18:32:07 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../Libft/libft.h"
# include "../MacroLibX-master/includes/mlx.h"
# include <fcntl.h>
# define HEIGHT 1080
# define WIDTH 1920

typedef struct s_calc
{
	float			x1;
	float			x2;
	float			y1;
	float			y2;
	unsigned int	col;
	int				nbr_y;
	int				nbr_x;
	float			nx;
	float			ny;
	int				z1;
	int				z2;
	int				diff;
}	t_calc;

typedef struct s_coord
{
	char				*all;
	int					z;
	char				*color;
	int					red;
	int					green;
	int					blue;
	unsigned int		all_color;
}				t_coord;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
}	t_vars;

/*fdf*/
void	msg_error(void);
/*check_data*/
int		check_lst(t_list *lst);
void	check_elem_line(t_coord **xyz);
/*init_tab*/
t_coord	**init_tab(t_list *lst);
/*manage_window*/
void	init_window(t_coord **xyz);
/*put_line*/
void	line_y(t_coord **xyz, t_vars *vars, t_calc *data);
void	line_x(int y, int x, t_calc *data, t_vars *vars);
void	line_x_all(t_coord **xyz, t_calc *data, t_vars *vars);
/*put_line_x*/
void	c_n_x_n(t_calc *data, t_vars *vars, float i, float c);
void	c_n_x_p(t_calc *data, t_vars *vars, float i, float c);
void	c_p_x_n(t_calc *data, t_vars *vars, float i, float c);
void	c_p_x_p(t_calc *data, t_vars *vars, float i, float c);
void	const_x(t_calc *data, t_vars *vars, float i);
/*put_line_y*/
void	c_n_y_n(t_calc *data, t_vars *vars, float i, float c);
void	c_n_y_p(t_calc *data, t_vars *vars, float i, float c);
void	c_p_y_n(t_calc *data, t_vars *vars, float i, float c);
void	c_p_y_p(t_calc *data, t_vars *vars, float i, float c);
void	const_y(t_calc *data, t_vars *vars, float i);
/*init_color*/
void	init_color(t_coord **xyz, int y);
/*color*/
void	color_red(t_coord **xyz, int y, int x);
void	color_green(t_coord **xyz, int y, int x);
void	color_blue(t_coord **xyz, int y, int x);
/*calc_coord*/
void	calc_data(t_coord **xyz, t_calc *data);
void	calc_coord(int y, int x, t_calc *data);
/*calc_utils*/
int		count_split(char **src);
int		count_tab(char const *s, char c);
int		count_x(t_coord **xyz, int y);
int		count_y(t_coord **xyz);
int		ft_roundf(float nb);
/*clear_error*/
void	lst_clear_all(t_list *lst);
void	free_two_tab(t_coord **xyz, char **dest);
void	clear_all_init(t_list *save, t_coord **xyz, int y);
void	clear_xyz(t_coord **xyz, int del_color);
void	clear_end(t_coord **xyz, t_calc *data);

#endif

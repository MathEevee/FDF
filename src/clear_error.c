/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:09:10 by matde-ol          #+#    #+#             */
/*   Updated: 2024/01/21 18:33:08 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_end(t_coord **xyz, t_calc *data)
{
	clear_xyz(xyz, 1);
	free(data);
}

void	lst_clear_all(t_list *lst)
{
	t_list	*lst_next;

	if (lst == NULL)
		return ;
	while (lst != NULL)
	{
		lst_next = lst->next;
		free(lst->content);
		free(lst);
		lst = lst_next;
	}
}

void	free_two_tab(t_coord **xyz, char **dest)
{
	int	x;
	int	y;

	y = 0;
	while (xyz[y] != NULL)
	{
		x = 0;
		while (xyz[y][x].all)
			free(xyz[y][x++].all);
		free(xyz[y]);
		y++;
	}
	ft_free_all_tab(dest);
	free(xyz);
}

void	clear_all_init(t_list *save, t_coord **xyz, int y)
{
	while (y > 0)
	{
		free(xyz[y]);
		y--;
	}
	free(xyz);
	lst_clear_all(save);
}

void	clear_xyz(t_coord **xyz, int del_color)
{
	int	y;
	int	x;
	int	i;

	y = count_y(xyz);
	while (y >= 0)
	{
		x = count_x(xyz, y);
		i = x;
		while (i >= 0)
		{
			free(xyz[y][i].all);
			if (del_color)
				free(xyz[y][i].color);
			i--;
		}
		free(xyz[y]);
		y--;
	}
	free(xyz);
}

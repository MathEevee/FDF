/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:09:10 by matde-ol          #+#    #+#             */
/*   Updated: 2024/01/06 21:43:51 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	free_two_tab(int y, t_coord **xyz, char **dest)
{
	while (y > 0)
	{
		free(xyz[y]);
		y--;
	}
	ft_free_all_tab(dest, count_tab(dest[y], y));
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

void	clear_xyz(t_coord **xyz)
{
	int	y;
	int	x;
	int	i;

	y = count_y(xyz);
	x = count_x(xyz);
	while (y >= 0)
	{
		i = x;
		while (i >= 0)
		{
			free(xyz[y][i].all);
			free(xyz[y][i].color);
			i--;
		}
		free(xyz[y]);
		y--;
	}
	free(xyz);
}

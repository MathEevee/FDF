/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 09:44:05 by matde-ol          #+#    #+#             */
/*   Updated: 2024/01/08 15:23:20 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*static int	check_color(t_coord **xyz)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	while (xyz[y] != NULL)
	{
		x = 0;
		while (xyz[y][x].all != NULL)
		{
			i = 0;
			while (xyz[y][x].all[i] != '\0')
			{
				if (xyz[y][x].all[i] == ',')
					return (1);
				i++;
			}
			x++;
		}
		y++;
	}
	return (0);
}*/

static void	char_to_int_z(t_coord **xyz)
{
	int	y;
	int	x;

	y = 0;
	while (xyz[y] != NULL)
	{
		x = 0;
		while (xyz[y][x].all != NULL)
		{
			xyz[y][x].z = ft_atoi(xyz[y][x].all);
			x++;
		}
		y++;
	}
}

static int	split_in_tab(t_list *lst, int y, t_coord **xyz)
{
	int		x;
	char	**dest;

	x = 0;
	dest = ft_split(lst->content, ' ');
	xyz[y] = ft_calloc(sizeof(t_coord), count_split(dest) + 1);
	if (xyz[y] == NULL)
	{
		free_two_tab(y, xyz, dest);
		return (-1);
	}
	while (dest[x] != NULL)
	{
		xyz[y][x].all = ft_strdup(dest[x]);
		x++;
	}
	xyz[y][x].all = NULL;
	ft_free_all_tab(dest, x);
	return (0);
}

t_coord	**init_tab(t_list *lst)
{
	int		y;
	t_list	*save;
	t_coord	**xyz;

	y = 0;
	xyz = ft_calloc(sizeof(t_coord *), ft_lstsize(lst) + 1);
	if (xyz == NULL)
		return (0);
	save = lst;
	while (lst != NULL)
	{
		if (split_in_tab(lst, y, xyz) == -1)
		{
			clear_all_init(save, xyz, y);
			return (NULL);
		}
		y++;
		lst = lst->next;
	}
	lst_clear_all(save);
	char_to_int_z(xyz);
	init_color(xyz, 0);
	return (xyz);
}

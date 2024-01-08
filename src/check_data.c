/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:00:50 by matde-ol          #+#    #+#             */
/*   Updated: 2024/01/08 10:16:30 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	check_lst_content(char *src)
{
	size_t	i;
	char	*sep;
	size_t	size;

	i = 0;
	sep = "0123456789, xABCDEF-";
	size = ft_strlen(src);
	while (i < size)
	{
		src[i] = ft_toupper_hexa(src[i]);
		if (ft_strchr(sep, src[i]) == 0 && (i > size))
			return (-1);
		i++;
	}
	return (0);
}

int	check_lst(t_list *lst)
{
	t_list	*start;

	start = lst;
	while (lst->next != NULL)
	{
		if (check_lst_content(lst->content) == -1)
		{
			lst_clear_all(start);
			write(2, "Error\n", 6);
			return (-1);
		}
		lst = lst->next;
	}
	lst = start;
	return (0);
}

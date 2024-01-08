/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 09:44:52 by matde-ol          #+#    #+#             */
/*   Updated: 2024/01/06 21:34:33 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_x(t_coord **xyz)
{
	int	x;

	x = 0;
	while (xyz[0][x + 1].all != NULL)
		x++;
	return (x);
}

int	count_y(t_coord **xyz)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (xyz[y + 1] != NULL)
	{
		x = 0;
		while (xyz[y + 1][x + 1].all != NULL)
			x++;
		y++;
	}
	return (y);
}

int	count_tab(char const *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
			words++;
		i++;
	}
	return (words);
}

int	count_split(char **src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 09:44:52 by matde-ol          #+#    #+#             */
/*   Updated: 2024/01/21 18:31:46 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_roundf(float nb)
{
	nb += 0.5;
	return (nb);
}

int	count_x(t_coord **xyz, int y)
{
	int	x;

	x = 0;
	while (xyz[y][x].all != NULL)
		x++;
	return (x - 1);
}

int	count_y(t_coord **xyz)
{
	int	y;

	y = 0;
	while (xyz[y] != NULL)
		y++;
	return (y - 1);
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

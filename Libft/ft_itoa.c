/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 09:23:48 by matde-ol          #+#    #+#             */
/*   Updated: 2023/11/17 02:59:34 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_n(int n)
{
	int	size_n;

	size_n = 0;
	if (n < 0)
	{
		size_n++;
		n = -n;
	}
	while (n != 0)
	{
		n = n / 10;
		size_n++;
	}
	return (size_n);
}

static char	*ft_dest_malloc(char *dest, int n)
{
	int		i;
	char	c;
	int		size;

	i = 0;
	size = ft_size_n(n);
	dest[size] = '\0';
	if (n < 0)
	{
		n = -n;
		dest[0] = '-';
		i++;
	}
	while (size > i)
	{
		c = n % 10 + '0';
		dest[size - 1] = c;
		n = n / 10;
		size--;
	}
	return (dest);
}

char	*ft_itoa(int n)
{
	char	*dest;

	if (n == -2147483648)
	{
		dest = ft_strdup("-2147483648");
		return (dest);
	}
	if (n == 0)
	{
		dest = ft_strdup("0");
		return (dest);
	}
	else
	{
		dest = malloc(sizeof (char) * ft_size_n(n) + 1);
		if (dest == NULL)
			return (NULL);
		ft_dest_malloc(dest, n);
	}
	return (dest);
}

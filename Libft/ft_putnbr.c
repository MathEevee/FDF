/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:02:07 by matde-ol          #+#    #+#             */
/*   Updated: 2023/11/19 18:11:54 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int nbr)
{
	int	i;

	i = 0;
	if (nbr == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (nbr < 0)
	{
		write (1, "-", 1);
		nbr = -nbr;
		i++;
	}
	if (nbr < 10)
		return (i + ft_putchar(nbr + '0'));
	else
	{
		i += ft_putnbr(nbr / 10);
		i += ft_putnbr(nbr % 10);
	}
	return (i);
}

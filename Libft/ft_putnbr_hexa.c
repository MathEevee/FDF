/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:22:47 by matde-ol          #+#    #+#             */
/*   Updated: 2023/11/19 18:10:12 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_hexa(size_t nbr, char *base)
{
	int	i;

	i = 0;
	if (nbr >= 16)
		i += ft_putnbr_hexa(nbr / 16, base);
	return (i + ft_putchar(base[nbr % 16]));
}

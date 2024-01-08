/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:45:50 by matde-ol          #+#    #+#             */
/*   Updated: 2023/11/19 16:45:04 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexa_pointer(void *pt, char *base)
{
	int	i;

	i = 0;
	if (pt == NULL)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	i += ft_putstr("0x");
	i += ft_putnbr_hexa((size_t)pt, base);
	return (i);
}

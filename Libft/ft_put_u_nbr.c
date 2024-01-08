/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:29:26 by matde-ol          #+#    #+#             */
/*   Updated: 2023/11/19 16:49:30 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_u_nbr(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr < 10)
		return (ft_putchar(nbr + '0'));
	else
	{
		i += ft_put_u_nbr(nbr / 10);
		i += ft_put_u_nbr(nbr % 10);
	}
	return (i);
}

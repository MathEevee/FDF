/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:24:22 by matde-ol          #+#    #+#             */
/*   Updated: 2023/11/01 15:50:12 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num && ((char *)ptr1)[i] == ((char *)ptr2)[i])
		i++;
	if (i == num)
		return (0);
	return (*(unsigned char *)(ptr1 + i) - *(unsigned char *)(ptr2 + i));
}

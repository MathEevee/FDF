/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:12:18 by matde-ol          #+#    #+#             */
/*   Updated: 2023/11/06 15:41:09 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t num)
{
	size_t			i;
	unsigned char	*dst1;

	dst1 = (unsigned char *)dst;
	if (src == NULL)
		return (0);
	if (dst <= src)
	{
		i = 0;
		while (i < num)
		{
			dst1[i] = *((unsigned char *)src + i);
			i++;
		}
	}
	else
	{
		i = num;
		while (i > 0)
		{
			dst1[i - 1] = *((unsigned char *)src + (i - 1));
			i--;
		}
	}
	return (dst);
}

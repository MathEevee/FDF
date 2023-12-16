/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:33:03 by matde-ol          #+#    #+#             */
/*   Updated: 2023/11/06 09:17:45 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const void	*ft_memchr(const void *ptr, int o, size_t num)
{
	size_t	i;

	i = 0;
	if (ptr == NULL || num == 0)
		return (NULL);
	if (*(unsigned char *)ptr == (unsigned char)o)
		return ((unsigned char *)ptr);
	if ((unsigned char)o == '\0')
		return (((unsigned char *)ptr + ft_strlen(ptr)));
	while (i < num)
	{
		if (((unsigned char *)ptr)[i] == (unsigned char)o)
			return (((unsigned char *)ptr + i));
		i++;
	}
	return (0);
}

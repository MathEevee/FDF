/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:05:36 by matde-ol          #+#    #+#             */
/*   Updated: 2023/11/06 14:40:31 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (c == '\0')
		return (((char *)s + ft_strlen(s)));
	while (i > 0)
	{
		if (s[i] == c)
			return (((char *)s + i));
		i--;
	}
	if (s[i] == (unsigned char)c)
		return (((char *)s));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:28:30 by matde-ol          #+#    #+#             */
/*   Updated: 2023/11/06 14:13:16 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int o)
{
	size_t	i;

	i = 0;
	if (str[0] == (unsigned char)o)
		return ((char *)str);
	if (str == NULL)
		return (NULL);
	if (o == '\0')
		return (((char *)str + ft_strlen(str)));
	while (str[i])
	{
		if (str[i] == o)
			return (((char *)str + i));
		i++;
	}
	return (0);
}

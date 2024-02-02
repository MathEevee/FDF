/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 07:27:46 by matde-ol          #+#    #+#             */
/*   Updated: 2024/01/18 13:55:41 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strchr_nbr(const char *str, int o)
{
	size_t	i;

	i = 0;
	if (str[0] == (unsigned char)o)
		return (0);
	if (str == NULL)
		return (0);
	if (o == '\0')
		return (ft_strlen(str));
	while (str[i])
	{
		if (str[i] == o)
			return (i);
		i++;
	}
	return (0);
}

int	ft_atoi_hexa(char *src)
{
	int		i;
	int		sum;
	char	*base;
	char	c;

	i = 0;
	sum = 0;
	base = "0123456789ABCDEF";
	while ((src[i] >= 9 && src[i] <= 13) || src[i] == 32)
		i++;
	while (ft_ishexa(src[i]) == 1 || src[i] != '\0')
	{
		c = ft_toupper_hexa(src[i]);
		sum = sum * ft_strlen(base) + ft_strchr_nbr(base, c);
		i++;
	}
	return (sum);
}

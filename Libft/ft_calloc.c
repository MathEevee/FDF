/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:11:19 by matde-ol          #+#    #+#             */
/*   Updated: 2023/11/06 14:58:59 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char				*tab;
	unsigned long long	check_size;

	if (nmemb == 0 || size == 0)
	{
		tab = malloc(1);
		return (tab);
	}
	if ((long long)nmemb < 0 || (long long)size < 0)
		return (0);
	check_size = nmemb * size;
	tab = malloc(check_size);
	if (tab == NULL)
		return (NULL);
	ft_bzero(tab, (nmemb * size));
	return (tab);
}

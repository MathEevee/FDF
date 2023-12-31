/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:12:19 by matde-ol          #+#    #+#             */
/*   Updated: 2023/11/29 17:12:10 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_all_tab(char **dest, int i)
{
	if (dest != NULL)
	{
		while (i > 0)
		{
			i--;
			free(dest[i]);
		}
		free(dest);
	}
	return (NULL);
}

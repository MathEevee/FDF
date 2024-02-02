/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:12:19 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/02 15:28:42 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_all_tab(char **dest)
{
	int	i;

	i = 0;
	if (dest != NULL)
	{
		while (dest[i] != NULL)
		{
			free(dest[i]);
			i++;
		}
		free(dest);
	}
	return (NULL);
}

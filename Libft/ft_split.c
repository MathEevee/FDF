/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 09:56:05 by matde-ol          #+#    #+#             */
/*   Updated: 2023/11/04 10:52:32 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
			words++;
		i++;
	}
	return (words);
}

static int	ft_count_letter(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static char	*ft_in_to_malloc(const char *s, char c)
{
	int		i;
	char	*dest;
	int		len;

	len = ft_count_letter(s, c);
	dest = malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	int		srci;
	int		j;
	char	**dest;

	srci = 0;
	j = 0;
	dest = ft_calloc((count_word(s, c) + 1), sizeof(char *));
	if (dest == NULL || s == NULL)
		return (NULL);
	while (j < count_word(s, c))
	{
		while (s[srci] == c)
			srci++;
		if (s[srci] != '\0')
		{
			dest[j] = ft_in_to_malloc(s + srci, c);
			if (dest[j] == NULL)
				return (ft_free_all_tab(dest));
			srci = srci + ft_count_letter(dest[j], c);
		}
		j++;
	}
	dest[j] = NULL;
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:33:39 by matde-ol          #+#    #+#             */
/*   Updated: 2023/12/01 15:03:05 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_security(char *reste, char *dest)
{
	if (reste == NULL || dest == NULL)
	{
		free(dest);
		free(reste);
		return (1);
	}
	return (0);
}

static char	*ft_loop_buffer(int fd)
{
	ssize_t	size;
	char	*buffer;
	char	*next;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	size = read(fd, buffer, BUFFER_SIZE);
	if (size == 0 || size == -1)
	{
		free(buffer);
		return (0);
	}
	buffer[size] = 0;
	if (size == BUFFER_SIZE && ft_strchr_bis(buffer) == -1)
	{
		next = ft_loop_buffer(fd);
		if (next != NULL)
			buffer = ft_strjoin_f(buffer, next);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*reste[1024];
	char		*dest;

	str = ft_loop_buffer(fd);
	if (reste[fd] != NULL && str != NULL)
		str = ft_strjoin_f(reste[fd], str);
	else if (str == NULL && reste[fd] != NULL)
		str = reste[fd];
	reste[fd] = NULL;
	if (str && ft_strchr_bis(str) != -1)
	{
		reste[fd] = ft_substr(str, ft_strchr_bis(str) + 1, ft_strlen(str));
		dest = ft_strlcpy_f(str, ft_strchr_bis(str) + 1);
		if (ft_security(reste[fd], dest) == 1)
			return (NULL);
		if (reste[fd] != NULL && reste[fd][0] == 0)
		{
			free(reste[fd]);
			reste[fd] = NULL;
		}
	}
	else
		dest = str;
	return (dest);
}

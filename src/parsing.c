/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:01:14 by matde-ol          #+#    #+#             */
/*   Updated: 2023/12/16 16:28:55 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



void	init_data(int fd)
{
	t_coord	**data;
	char	*str;
	char	**dest;
	int		z;

	z = 0;
	*data = malloc(sizeof(t_coord *) * (line_count(fd) + 1));
	if (*data == NULL)
		return (NULL);
	while (str != NULL)
	{
		str = get_next_line(fd);
		dest = ft_split(str, ' ');
		data[z] = 

	}
}

char	*file_name(char *av)
{
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd <= 0)
	{
		close(fd);
		write (1, "Error\n", 6);
		return (0);
	}
	else
		init_data(fd);
	return (0);
}
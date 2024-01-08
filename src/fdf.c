/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:25:46 by matde-ol          #+#    #+#             */
/*   Updated: 2024/01/08 15:22:45 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	msg_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

static int	check_fd(char **av)
{
	int		fd;
	char	*src;

	src = av[1];
	fd = open(src, O_RDONLY);
	if (fd <= 0)
	{
		close(fd);
		return (-1);
	}
	else
		return (0);
}

static t_list	*init_lst(char **av)
{
	int		fd;
	t_list	*lst;
	char	*str;

	fd = open(av[1], O_RDONLY);
	str = get_next_line(fd);
	if (str[ft_strlen(str) - 1] == '\n')
		str[ft_strlen(str) - 1] = 0;
	lst = ft_lstnew(str);
	while (str != NULL)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		if (str[ft_strlen(str) - 1] == '\n')
			str[ft_strlen(str) - 1] = 0;
		ft_lstadd_back(&lst, ft_lstnew(str));
	}
	close(fd);
	return (lst);
}

int	main(int ac, char **av)
{
	t_list	*lst;
	t_coord	**xyz;


	if (ac != 2)
	{
		msg_error();
		return (0);
	}
	if (check_fd(av) == -1)
		return (0);
	lst = init_lst(av);
	if (check_lst(lst) == -1)
		return (0);
	xyz = init_tab(lst);
	if (xyz == NULL)
	{
		msg_error();
		return (0);
	}
	//print_all(xyz);
	init_window(xyz);
	clear_xyz(xyz);
	return (0);
}

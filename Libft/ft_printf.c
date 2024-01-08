/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 03:29:05 by matde-ol          #+#    #+#             */
/*   Updated: 2023/11/23 17:23:03 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_security(char c)
{
	if (c != '\0')
	{
		ft_putchar('%');
		ft_putchar(c);
		return (2);
	}
	return (0);
}

int	ft_printf_conditions(const char *format, size_t i, va_list args)
{
	char	*hexa_min;
	char	*hexa_maj;

	hexa_min = "0123456789abcdef";
	hexa_maj = "0123456789ABCDEF";
	if (format[i] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format[i] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format[i] == 'p')
		return (ft_hexa_pointer(va_arg(args, void *), hexa_min));
	else if (format[i] == 'd' || format[i] == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format[i] == 'u')
		return (ft_put_u_nbr(va_arg(args, unsigned int)));
	else if (format[i] == 'x')
		return (ft_putnbr_hexa(va_arg(args, unsigned int), hexa_min));
	else if (format[i] == 'X')
		return (ft_putnbr_hexa(va_arg(args, unsigned int), hexa_maj));
	else if (format[i] == '%')
		return (ft_putchar('%'));
	else
		return (ft_security(format[i]));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		charnbr;
	size_t	i;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	i = 0;
	charnbr = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i++]);
			charnbr++;
		}
		else
		{
			i++;
			charnbr = charnbr + ft_printf_conditions(format, i, args);
			i++;
		}
	}
	va_end(args);
	return (charnbr);
}

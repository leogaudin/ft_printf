/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:55:33 by lgaudin           #+#    #+#             */
/*   Updated: 2023/04/21 12:58:03 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_parser(const char *format, int *i, va_list args)
{
	int	count;

	count = 0;
	if (format[*i] == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (format[*i] == 's')
		count += ft_print_string(va_arg(args, char *));
	else if (format[*i] == 'p')
		count += ft_print_pointer(va_arg(args, unsigned long long));
	else if (format[*i] == 'd' || format[*i] == 'i')
		count += ft_print_int(va_arg(args, int));
	else if (format[*i] == 'u')
		count += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format[*i] == 'x' || format[*i] == 'X')
		count += ft_print_hexa(va_arg(args, unsigned int), format[*i]);
	else if (format[*i] == '%')
		count += ft_print_percent();
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_parser(format, &i, args);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	char* format = "Hello World! %x %d %s %p %i %c %x %% %u\n";
// 	printf(format, 1234, 1234, "Hello World!", "Hello World!", 1234, 'c', 1234, 1234, 1234);
// 	ft_printf(format, 1234, 1234, "Hello World!", "Hello World!", 1234, 'c', 1234, 1234, 1234);
// 	return (0);
// }

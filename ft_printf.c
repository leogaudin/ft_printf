/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:55:33 by lgaudin           #+#    #+#             */
/*   Updated: 2023/04/21 19:35:18 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_parse_flags(const char *format, int *i, t_flags *flags)
{
	while (format[*i] == '-' || format[*i] == '0' || format[*i] == '*'
		|| format[*i] == '+' || format[*i] == '#' || format[*i] == ' ')
	{
		if (format[*i] == '-')
			flags->minus = 1;
		else if (format[*i] == '0')
			flags->zero = 1;
		else if (format[*i] == '*')
			flags->star = 1;
		else if (format[*i] == '+')
			flags->plus = 1;
		else if (format[*i] == '#')
			flags->hash = 1;
		else if (format[*i] == ' ')
			flags->space = 1;
		// else if (ft_isdigit(format[*i]))
		// 	flags->width = ft_atoi(&format[*i]);
		(*i)++;
	}
}

int	ft_parse_precision(const char *format, int *i, t_flags *flags)
{
	int	count;

	count = 0;
	if (format[*i] == '.')
	{
		*i += 1;
		flags->precision = ft_atoi(&format[*i]);
		*i += ft_intlen(flags->precision);
		count++;
	}
	return (count);
}

int	ft_parser(const char *format, int *i, va_list *args)
{
	int		count;
	t_flags	flags;

	ft_memset(&flags, 0, sizeof(t_flags));
	ft_parse_flags(format, i, &flags);
	count = 0;
	if (format[*i] == 'c')
		count += ft_print_char(va_arg(*args, int));
	else if (format[*i] == 's')
		count += ft_print_string(va_arg(*args, char *));
	else if (format[*i] == 'p')
		count += ft_print_pointer(va_arg(*args, unsigned long long), &flags);
	else if (format[*i] == 'd' || format[*i] == 'i')
		count += ft_print_int(va_arg(*args, int), &flags);
	else if (format[*i] == 'u')
		count += ft_print_unsigned(va_arg(*args, unsigned int));
	else if (format[*i] == 'x' || format[*i] == 'X')
		count += ft_print_hexa(va_arg(*args, unsigned int), format[*i], &flags);
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
			count += ft_parser(format, &i, &args);
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

int	main(void)
{
	int printf_return;
	int ft_printf_return;

	printf_return = printf("Hello %#p\n", "Salut");
	ft_printf_return = ft_printf("Hello %#p\n", "Salut");
	printf("Printf: %d and ft_printf: %d\n", printf_return, ft_printf_return);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:55:33 by lgaudin           #+#    #+#             */
/*   Updated: 2023/04/21 16:20:24 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_parser(const char *format, int *i, va_list *args)
{
	int	count;

	count = 0;
	if (format[*i] == 'c')
		count += ft_print_char(va_arg(*args, int));
	else if (format[*i] == 's')
		count += ft_print_string(va_arg(*args, char *));
	else if (format[*i] == 'p')
		count += ft_print_pointer(va_arg(*args, unsigned long long));
	else if (format[*i] == 'd' || format[*i] == 'i')
		count += ft_print_int(va_arg(*args, int));
	else if (format[*i] == 'u')
		count += ft_print_unsigned(va_arg(*args, unsigned int));
	else if (format[*i] == 'x' || format[*i] == 'X')
		count += ft_print_hexa(va_arg(*args, unsigned int), format[*i]);
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

// int	main(void)
// {
// 	int printf_return;
// 	int ft_printf_return;

// 	printf_return = printf("AD-Lq%s`37_Y7N^%sCJv)dfB%pz2 %sHdmlgXt\t!%di*<x", "qh{4'Y!\fN( >\fU(os@d${c0F`>pf?[&fkv2gQM0\ftw8ADX\\ST7%L`-!EVzwuyC'{vbH?'j;0?]", "g}UNu\n\\WJ%N/|Y1_pDGXV\tuXyqt2GNi=/=T(3\\mxbo|TeMA/`C\nRj}'&;oiC;A\tg];&Tf,2;uo$>60=", (void *)7204731406881973531, "rSQzaR\"TOQ{2:>du>]lLL8\rWFvS\rkHsOdpsA[1O!NIWX}CMI>^RA|2-\r5,)q p", -499624224);
// 	ft_printf_return = ft_printf("AD-Lq%s`37_Y7N^%sCJv)dfB%pz2 %sHdmlgXt\t!%di*<x", "qh{4'Y!\fN( >\fU(os@d${c0F`>pf?[&fkv2gQM0\ftw8ADX\\ST7%L`-!EVzwuyC'{vbH?'j;0?]", "g}UNu\n\\WJ%N/|Y1_pDGXV\tuXyqt2GNi=/=T(3\\mxbo|TeMA/`C\nRj}'&;oiC;A\tg];&Tf,2;uo$>60=", (void *)7204731406881973531, "rSQzaR\"TOQ{2:>du>]lLL8\rWFvS\rkHsOdpsA[1O!NIWX}CMI>^RA|2-\r5,)q p", -499624224);
// 	printf("Printf returned %d and ft_printf returned %d\n", printf_return, ft_printf_return);
// 	return (0);
// }

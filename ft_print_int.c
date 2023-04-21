/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:54:20 by lgaudin           #+#    #+#             */
/*   Updated: 2023/04/21 19:07:00 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int n, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->plus && n >= 0)
		count += ft_print_char('+');
	else if (flags->space && n >= 0)
		count += ft_print_char(' ');
	count += ft_intlen(n);
	ft_putnbr_fd(n, 1);
	return (count);
}

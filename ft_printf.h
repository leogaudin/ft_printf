/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:47:19 by lgaudin           #+#    #+#             */
/*   Updated: 2023/07/01 18:29:34 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_flags
{
	int	plus;
	int	hash;
	int	space;
}		t_flags;

int		ft_printf(const char *format, ...);
int		ft_print_char(int c);
int		ft_print_string(char *str);
int		ft_print_hexa(unsigned long long n, char c, t_flags *flags);
int		ft_print_pointer(unsigned long long p, t_flags *flags);
int		ft_print_int(int n, t_flags *flags);
int		ft_print_unsigned(unsigned int n);
int		ft_print_percent(void);
int		ft_parser(const char *format, int *i, va_list *args);
int		ft_intlen(long n);

#endif

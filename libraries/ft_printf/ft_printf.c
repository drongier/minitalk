/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:46:17 by drongier          #+#    #+#             */
/*   Updated: 2023/08/18 17:48:14 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, const char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += ft_print_char(va_arg(args, int));
	else if (format == 's')
		print_len += ft_print_str(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		print_len += ft_print_num(va_arg(args, int));
	else if (format == 'p')
		print_len += ft_print_ptr(va_arg(args, unsigned long));
	else if (format == 'x' || format == 'X')
		print_len += ft_print_hexa(va_arg(args, unsigned int), format);
	else if (format == 'u')
		print_len += ft_print_unsi(va_arg(args, unsigned int));
	else if (format == '%')
		print_len += ft_print_char('%');
	else
	{
		print_len += ft_print_char('%'); 
		print_len += ft_print_char(format);
	}
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		print_len;

	i = 0;
	print_len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_len += ft_format(args, str[i + 1]);
			i++;
		}
		else 
			print_len += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (print_len);
}

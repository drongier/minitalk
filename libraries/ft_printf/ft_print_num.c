/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 18:28:44 by drongier          #+#    #+#             */
/*   Updated: 2023/08/18 18:28:47 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_num(int n)
{
	int		count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		count += ft_print_char('-');
		count += ft_print_num(n * -1);
	}
	else
	{
		if (n > 9)
			count += ft_print_num(n / 10);
		count += ft_print_char(n % 10 + '0');
	}
	return (count);
}

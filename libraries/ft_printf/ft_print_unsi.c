/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 18:33:19 by drongier          #+#    #+#             */
/*   Updated: 2023/08/18 18:34:18 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsi(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_print_unsi(n / 10);
	count += ft_print_char((n % 10) + '0');
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:03:30 by drongier          #+#    #+#             */
/*   Updated: 2023/08/18 19:07:36 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(size_t pointer)
{
	char	string[25];
	int		i;
	int		count;
	char	*base_character;

	base_character = "0123456789abcdef";
	i = 0;
	if (pointer == 0)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	while (pointer != 0)
	{
		string[i] = base_character[pointer % 16];
		pointer = pointer / 16;
		i++;
	}
	count = i + 2;
	while (i--)
		ft_print_char(string[i]);
	return (count);
}

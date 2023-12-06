/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:56:22 by drongier          #+#    #+#             */
/*   Updated: 2023/08/18 19:12:49 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int	ft_print_char(int c);
int	ft_print_num(int n);
int	ft_print_str(char *str);
int	ft_print_ptr(size_t pointer);
int	ft_print_hexa(unsigned int num, const char format);
int	ft_printf(const char *str, ...);
int	ft_print_unsi(unsigned int n);
int	ft_print_num(int n);

#endif

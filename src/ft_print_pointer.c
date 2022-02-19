/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeser <aeser@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 23:23:00 by aeser             #+#    #+#             */
/*   Updated: 2022/02/20 00:01:56 by aeser            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	ft_pointer_len(unsigned	long number)
{
	int	count;

	count = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number /= 16;
		count++;
	}
	return (count);
}

static int	ft_print_pointer(unsigned long long number, const char format)
{
	if (number == 0)
		return (ft_print_char('0'));
	if (number >= 16)
	{
		ft_print_pointer(number / 16, format);
		ft_print_pointer(number % 16, format);
	}
	else
	{
		if (number <= 9)
			ft_putchar_fd('0' + number, 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((number - 10 + 'a'), 1);
			else if (format == 'X')
				ft_putchar_fd((number - 10 + 'A'), 1);
		}
	}
	return (ft_pointer_len(number));
}

int	ft_print_ptr(unsigned long long addr)
{
	int	written;

	written = 0;
	written += ft_print_string("0x");
	written += ft_print_pointer(addr, 'x');
	return (written);
}

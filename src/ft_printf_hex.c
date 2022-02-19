/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeser <aeser@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:07:55 by aeser             #+#    #+#             */
/*   Updated: 2022/02/19 18:10:00 by aeser            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

static int	ft_hex_len(unsigned long long number)
{
	int	count;

	count = 0;
	while (number != 0)
	{
		number /= 16;
		count++;
	}
	return (count);
}

int	ft_print_hex(unsigned long long number, char format)
{
	if (number == 0)
	{
		ft_putnbr_fd(0, 1);
		return (1);
	}
	if (number >= 16)
	{
		ft_print_hex(number / 16, format);
		ft_print_hex(number % 16, format);
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
	return (ft_hex_len(number));
}

int	ft_print_ptr(unsigned long long addr)
{
	int	written;

	written = 0;
	written += write(1, "0x", 2);
	written += ft_print_hex(addr, 'x');
	return (written);
}

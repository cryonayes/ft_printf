/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeser <aeser@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:56:35 by aeser             #+#    #+#             */
/*   Updated: 2022/02/19 16:56:35 by aeser            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_print_number(int nbr)
{
	int		written;
	char	*number;

	written = 0;
	number = ft_itoa(nbr);
	written = ft_print_string(number);
	free(number);
	return (written);
}

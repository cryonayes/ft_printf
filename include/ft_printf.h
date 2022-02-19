/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeser <aeser@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:06:33 by aeser             #+#    #+#             */
/*   Updated: 2022/02/19 17:07:35 by aeser            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *format, ...);
int	ft_print_char(const int chr);
int	ft_print_string(const char *str);
/*
int	ft_print_percent(void);
int	ft_print_number(int nbr);
int	ft_print_unsigned(unsigned int nbr);
int	ft_print_hex(unsigned int hex, const char format);
int	ft_print_pointer(unsigned long long ptr);
*/
#endif

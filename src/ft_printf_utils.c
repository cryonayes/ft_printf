#include "libft.h"
#include "ft_printf.h"

int	ft_print_char(const int chr)
{
	write(1, &chr, 1);
	return (1);
}

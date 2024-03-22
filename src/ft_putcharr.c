#include "ft_printf.h"

char	ft_putcharr(char const c, int count)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	count++;
	return (count);
}


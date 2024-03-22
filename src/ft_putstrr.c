#include "ft_printf.h"

int	ft_putstrr(char const *s, int count)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		count += 6;
		return (count);
	}
	while (s[i])
	{
		while (s[i] != '\0')
		{
			if (write(1, &s[i], 1) == -1)
				return (-1);
			count++;
			i++;
		}
	}
	return (count);
}

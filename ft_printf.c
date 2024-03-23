/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmore-oj <jmore-oj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:38:30 by jmore-oj          #+#    #+#             */
/*   Updated: 2024/03/23 20:09:13 by jmore-oj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_vselect(char const s, va_list args)
{
	int	count;

	count = 0;
	if (s == 'c')
		count = ft_putchr(va_arg(args, int));
	else if (s == 's')
		count = ft_putstrr(va_arg(args, char *));
	else if (s == 'p')
		count = ft_puthex(va_arg(args, unsigned long), "0123456789abcdef", 1);
	else if (s == 'i' || s == 'd')
		count = ft_putnbrr(va_arg(args, int));
	else if (s == 'u')
		count = ft_putnbrr(va_arg(args, unsigned int));
	else if (s == 'x')
		count = ft_puthex(va_arg(args, unsigned int), "0123456789abcdef", 0);
	else if (s == 'X')
		count = ft_puthex(va_arg(args, unsigned int), "0123456789ABCDEF", 0);
	else if (s == '%')
		count = ft_putchr('%');
	else
		count = -1;
	return (count);
}

static int	ft_check(char const *s, va_list args)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			count = ft_vselect((char)s[i], args);
			if (count == -1)
				return (-1);
		}
		else
		{
			if (write(1, &s[i], 1) == -1)
				return (-1);
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		c;

	c = 0;
	va_start(args, s);
	c = ft_check(s, args);
	va_end(args);
	return (c);
}
/*
int	main(void)
{
	char	*c = "Miniminiminiminililooooo";

	ft_printf("ft_print Lenght = %d\n", ft_printf("My name is %s\n", c));
	printf("printf Lenght = %d\n", ("My name is %s\n", c));
	return (0);
}*/

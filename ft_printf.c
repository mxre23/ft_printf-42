/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmore-oj <jmore-oj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:38:30 by jmore-oj          #+#    #+#             */
/*   Updated: 2024/03/24 20:21:44 by jmore-oj         ###   ########.fr       */
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
	if (count == -1)
		return (-1);
	return (count);
}

int	ft_printf(char const *s, ...)
{
	int		i;
	int		count;
	int		total;
	va_list	args;

	i = 0;
	count = 0;
	total = 0;
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
			count = ft_vselect(s[++i], args);
		else
			count = write (1, &s[i], 1);
		if (count == -1)
			return (-1);
		total += count;
		i++;
	}
	va_end(args);
	return (total);
}
/*
int	main(void)
{
	unsigned long	hex = -5000000000;

	ft_printf("mia %d\n", -10);	
	printf("printf %d\n", -10);
	ft_printf("ft_printf %%\n");
	printf("printf %%\n");
	ft_printf("mia %x\n", hex);
	return (0);
}*/

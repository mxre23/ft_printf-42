/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmore-oj <jmore-oj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:38:30 by jmore-oj          #+#    #+#             */
/*   Updated: 2024/03/21 22:24:45 by jmore-oj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_vselect(char const s, va_list args, int count)
{
	if (s == 'c')
		count = ft_putcharr(va_arg(args, int), count);
	else if (s == 's')
		count = ft_putstrr(va_arg(args, char *), count);
	else if (s == 'p')
		count = ft_putptr(va_arg(args, void *), count);
	else if (s == 'i' || s == 'd')
		count == ft_putnbrr(va_arg(args, int), count);
	else if (s == 'u')
		count = ft_putuns(va_arg(args, unsigned int), count);
	else if (s == 'x')
		count = ft_puthexalow(va_arg(args, unsigned int), count);
	else if (s == 'X')
		count = ft_hexaup(va_arg(args, long int), count);
	else if (s == '%')
		count = ft_putchar('%', count);
	else
		count = -1;
	return (count);
}

static int	ft_check(char const *s, va_list args, int count)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			count = ft_vselect((char)s[i], args, count);
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
	c = ft_check(s, args, c);
	va_end(args);
	return (c);
}

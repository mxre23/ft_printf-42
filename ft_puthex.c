/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmore-oj <jmore-oj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:42:25 by jmore-oj          #+#    #+#             */
/*   Updated: 2024/03/23 19:37:58 by jmore-oj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_puthex(unsigned long nbr, char *base, int isptr)
{
	int	count;
	int	check;

	len = 0;
	if (isptr == 1)
	{
		if (ft_putstrr("0x") == -1)
			return (-1);
		count += 2;
	}
	if (nbr > 15)
	{
		check = ft_putex(nbr / 16, base, 0);
		if (check == -1 || ft_putchar(base[(nbr % 16)]) == -1)
			return (-1);
		count += check + 1;
	}
	else
	{
		if (ft_putchr(base[nbr]) == -1)
			return (-1);
		count++;
	}
	return (count);
}

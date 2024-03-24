/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmore-oj <jmore-oj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:42:25 by jmore-oj          #+#    #+#             */
/*   Updated: 2024/03/24 17:19:51 by jmore-oj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_puthex(unsigned long nbr, char *base, int isptr)
{
	int	count;
	int	check;

	count = 0;
	if (isptr == 1)
	{
		if (ft_putstrr("0x") == -1)
			return (-1);
		count += 2;
	}
	if (nbr > 15)
	{
		check = ft_puthex(nbr / 16, base, 0);
		if (check == -1 || ft_putchr(base[(nbr % 16)]) == -1)
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

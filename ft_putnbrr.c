/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmore-oj <jmore-oj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:11:02 by jmore-oj          #+#    #+#             */
/*   Updated: 2024/03/23 18:19:23 by jmore-oj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_putnbrr(long nbr)
{
	int	count;
	int	check;

	count = 0;
	if (nbr < 0)
	{
		if (ft_putchr('-') == -1)
			return (-1);
		count++;
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		check = ft_putnbr(nbr / 10);
		if (check == -1 || ft_putchr((nbr % 10) + 48 == -1))
			return (-1);
		count += check + 1;
	}
	else
	{
		if (ft_putchr(nbr + 48) == -1)
			return (-1);
		count++;
	}
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmore-oj <jmore-oj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:53:08 by jmore-oj          #+#    #+#             */
/*   Updated: 2024/03/23 20:17:53 by jmore-oj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstrr(char const *s)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
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

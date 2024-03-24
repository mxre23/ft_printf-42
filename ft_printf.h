/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmore-oj <jmore-oj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:55:44 by jmore-oj          #+#    #+#             */
/*   Updated: 2024/03/24 19:10:08 by jmore-oj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(char const *s, ...);
int		ft_putchr(char c);
int		ft_putstrr(char *s);
long	ft_putnbrr(long nbr);
long	ft_puthex(unsigned long nbr, char *base, int isptr);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmore-oj <jmore-oj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:06:10 by jmore-oj          #+#    #+#             */
/*   Updated: 2024/03/21 22:24:52 by jmore-oj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

int		ft_printf(char const *s, ...);
int		ft_putcharr(char const c, int count);
int		ft_putnbrr(int n, int count);
int		ft_puthexalow(unsigned long hex, int count);
int		ft_puthexaup(unsigned int hexa, int count);
int		ft_putptr(void *ptr, int count);
int		ft_putstrr(char const *s, int count);
int		ft_putuns(unsigned int n, int count);

#endif

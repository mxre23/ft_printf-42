/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmore-oj <jmore-oj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:38:30 by jmore-oj          #+#    #+#             */
/*   Updated: 2024/03/16 17:59:41 by jmore-oj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*ft_putstr(char *s)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	while(*s != % && i < len)
	{
		write(1, &s[i++], 1);
	}
}
 
int	ft_printf(char const *, ...)
{
	va_list	args;




	va_start(args, s);


}

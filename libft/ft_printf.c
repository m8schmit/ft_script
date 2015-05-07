/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschmit <mschmit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 11:55:46 by mschmit           #+#    #+#             */
/*   Updated: 2014/04/16 11:55:46 by mschmit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

static char	ft_flag(char flag)
{
	if (flag == '-' || flag == '+' || flag == '#' || flag == '0' || flag == ' ')
		return (flag);
	else
		return (0);
}

static int	ft_arg(char c, va_list ap, char flag)
{
	char	*s;

	flag = ft_flag(flag);
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 's')
	{
		if ((s = va_arg(ap, char *)) != NULL)
			return (ft_putstr(s));
		else
			return (ft_putstr("(null)"));
	}
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (c == 'u' || c == 'o' || c == 'x')
		return (ft_putnbru(va_arg(ap, unsigned int), c));
	else if (c == 'p')
		return (ft_putpoint(va_arg(ap, long unsigned int)));
	else
		return (ft_putchar(c));
}

int			ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		result;
	char	flag;

	i = 0;
	result = 0;
	va_start(ap, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			i++;
			flag = s[i];
			i = i + ft_sizei((char *)&s[i]);
			result = result + ft_arg(s[i], ap, flag);
		}
		else
			result = result + ft_putchar(s[i]);
		i++;
	}
	va_end(ap);
	return (result);
}

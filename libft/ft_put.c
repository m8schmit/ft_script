/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschmit <mschmit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 11:55:46 by mschmit           #+#    #+#             */
/*   Updated: 2014/04/16 11:55:46 by mschmit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define CF ft_putchar_fd

int	ft_putnbru(unsigned int n, int b)
{
	if (b == 'u')
		b = 10;
	else if (b == 'o')
		b = 8;
	else if (b == 'x' || b == 'p')
		b = 16;
	if (n < (unsigned int)b)
	{
		if (n < 10)
			return (ft_putchar(n + '0'));
		else
			return (ft_putchar(n - 10 + 'a'));
	}
	else
	{
		if ((n % b) < 10)
			return (ft_putnbru((n / b), b) + ft_putchar((n % b) + '0'));
		else
			return (ft_putnbru((n / b), b) + ft_putchar((n % b) - 10 + 'a'));
	}
}

int	ft_putnbru_fd(unsigned int n, int b, int fd)
{
	if (b == 'u')
		b = 10;
	else if (b == 'o')
		b = 8;
	else if (b == 'x' || b == 'p')
		b = 16;
	if (n < (unsigned int)b)
	{
		if (n < 10)
			return (CF(n + '0', fd));
		else
			return (CF(n - 10 + 'a', fd));
	}
	else
	{
		if ((n % b) < 10)
			return (ft_putnbru_fd((n / b), b, fd) + CF((n % b) + '0', fd));
		else
			return (ft_putnbru_fd((n / b), b, fd) + CF((n % b) - 10 + 'a', fd));
	}
}

int	ft_putpoint_fd(long unsigned int n, int fd)
{
	if (n < 16)
	{
		if (n < 10)
			return (ft_putstr_fd("0x", fd) + CF(n + '0', fd));
		else
			return (ft_putstr_fd("0x", fd) + CF(n - 10 + 'a', fd));
	}
	else
	{
		if ((n % 16) < 10)
			return (ft_putpoint_fd(n / 16, fd) + CF((n % 16) + '0', fd));
		else
			return (ft_putpoint_fd(n / 16, fd) + CF((n % 16) - 10 + 'a', fd));
	}
}

int	ft_putpoint(long unsigned int n)
{
	if (n < 16)
	{
		if (n < 10)
			return (ft_putstr("0x") + ft_putchar(n + '0'));
		else
			return (ft_putstr("0x") + ft_putchar(n - 10 + 'a'));
	}
	else
	{
		if ((n % 16) < 10)
			return (ft_putpoint(n / 16) + ft_putchar((n % 16) + '0'));
		else
			return (ft_putpoint(n / 16) + ft_putchar((n % 16) - 10 + 'a'));
	}
}

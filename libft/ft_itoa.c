/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschmit <mschmit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 11:55:46 by mschmit           #+#    #+#             */
/*   Updated: 2014/04/16 11:55:46 by mschmit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <string.h>

static void	ft_nbrinchar(int n, char *str, int i)
{
	if (n >= 0)
	{
		if (n >= 10)
		{
			ft_nbrinchar(n / 10, str, i + 1);
			str[ft_strlen(str)] = n % 10 + '0';
		}
		else
		{
			str[ft_strlen(str)] = '0' + n;
		}
	}
	else
	{
		str[0] = '-';
		ft_nbrinchar(-n, str, i + 1);
	}
}

char		*ft_itoa(int n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 13);
	if (str && n <= INT_MAX && n >= INT_MIN)
	{
		ft_bzero(str, 11);
		ft_nbrinchar(n, str, 0);
	}
	if (n == INT_MIN)
	{
		ft_bzero(str, 11);
		ft_nbrinchar(n + 1, str, 0);
		str[10] = '8';
	}
	str[ft_strlen(str)] = '\0';
	return (str);
}

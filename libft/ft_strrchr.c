/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschmit <mschmit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 11:55:47 by mschmit           #+#    #+#             */
/*   Updated: 2014/04/16 11:55:47 by mschmit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	n;
	size_t	i;

	i = 0;
	n = ft_strlen((char *)s);
	if ((char)c == 0)
		return (char *)(s + n);
	while (i < n)
	{
		if (s[n - i] == (char)c)
			return ((char *)(&s[n - i]));
		i++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

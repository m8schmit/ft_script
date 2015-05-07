/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschmit <mschmit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 11:55:46 by mschmit           #+#    #+#             */
/*   Updated: 2014/04/16 11:55:46 by mschmit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s2)
	{
		while (i < n)
		{
			*((char *)s1 + i) = *((char *)s2 + i);
			i++;
		}
		return (s1);
	}
	else
		return (0);
}

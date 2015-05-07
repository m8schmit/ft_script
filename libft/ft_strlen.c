/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschmit <mschmit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 11:55:47 by mschmit           #+#    #+#             */
/*   Updated: 2014/04/16 11:55:47 by mschmit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_strlen(const char *s)
{
	const char	*str;

	if (s == NULL)
		return (0);
	str = s;
	while (*str)
		str++;
	return (str - s);
}

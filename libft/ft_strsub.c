/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschmit <mschmit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 11:55:48 by mschmit           #+#    #+#             */
/*   Updated: 2014/04/16 11:55:48 by mschmit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (!s)
		return (NULL);
	if ((ret = ft_strnew(len)) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = s[start + i];
		++i;
	}
	return (ret);
}

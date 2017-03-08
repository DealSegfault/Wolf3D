/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:00:03 by mhalit            #+#    #+#             */
/*   Updated: 2016/11/16 03:47:12 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *srce, int c, size_t n)
{
	char		*d;
	const char	*s;

	d = dest;
	s = srce;
	while (n--)
	{
		if (*s == (char)c)
		{
			*d++ = *s++;
			return ((unsigned char *)d);
		}
		*d++ = *s++;
	}
	return (0);
}

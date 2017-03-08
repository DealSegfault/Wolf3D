/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:01:19 by mhalit            #+#    #+#             */
/*   Updated: 2016/11/07 19:18:18 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *dest;

	dest = (unsigned char *)s;
	if ((unsigned int)n <= 0)
		return (s);
	while ((unsigned int)n-- > 0)
		*dest++ = (unsigned char)c;
	return (s);
}

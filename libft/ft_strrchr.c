/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:04:58 by mhalit            #+#    #+#             */
/*   Updated: 2016/11/09 21:25:10 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	tmp;

	tmp = (unsigned char)c;
	i = 0;
	while (s[i])
		i++;
	while (i > -1)
	{
		if (((unsigned char*)s)[i] == tmp)
			return ((char*)(s + i));
		i--;
	}
	return (NULL);
}

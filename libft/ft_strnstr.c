/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:24:07 by mhalit            #+#    #+#             */
/*   Updated: 2016/11/20 22:52:22 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int i;
	unsigned int a;

	i = 0;
	a = 0;
	if (!little[i])
		return ((char *)big);
	while (big[i] && i < len)
	{
		while (big[i + a] == little[a] && (i + a < len))
		{
			a++;
			if (little[a] == '\0')
				return ((char *)big + i);
		}
		a = 0;
		i++;
	}
	return (0);
}

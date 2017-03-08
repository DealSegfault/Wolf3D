/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:05:53 by mhalit            #+#    #+#             */
/*   Updated: 2016/11/05 21:24:11 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int a;

	i = 0;
	a = 0;
	if (!*little)
		return ((char *)big);
	while (big[i])
	{
		while (big[i + a] == little[a])
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:16:31 by mhalit            #+#    #+#             */
/*   Updated: 2016/11/22 00:16:31 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*out;
	int		i;

	i = 0;
	out = NULL;
	if (s != NULL && f != NULL)
	{
		out = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
		if (out == NULL)
			return (NULL);
		while (s[i])
		{
			out[i] = f(s[i]);
			i++;
		}
		out[i] = '\0';
		return (out);
	}
	return (NULL);
}

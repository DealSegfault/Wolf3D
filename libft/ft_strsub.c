/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:01:22 by mhalit            #+#    #+#             */
/*   Updated: 2016/11/14 16:31:52 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s1, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;

	out = malloc(sizeof(char) * (len + 1));
	if (out == NULL || s1 == NULL)
		return (NULL);
	i = 0;
	while (s1[start] && i < len)
	{
		out[i] = s1[start];
		i++;
		start++;
	}
	out[i] = '\0';
	return (out);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:30:43 by mhalit            #+#    #+#             */
/*   Updated: 2016/11/16 05:23:16 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_sp(char c)
{
	return (c == ',' || c == ' ' || c == '\n' || c == '\t');
}

char			*ft_strtrim(char const *s)
{
	char		*out;
	size_t		j;

	if (!s)
		return (0);
	out = ft_strdup(s);
	if (out == NULL)
		return (NULL);
	while (is_sp(*out))
		out++;
	j = ft_strlen(out) - 1;
	while (is_sp(out[j]))
		j--;
	out[++j] = '\0';
	return (ft_strdup(out));
}

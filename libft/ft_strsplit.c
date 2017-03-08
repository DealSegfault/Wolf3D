/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:55:36 by mhalit            #+#    #+#             */
/*   Updated: 2016/11/18 17:57:20 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_du_futur(char *str, char c, int i)
{
	int	st;

	st = i;
	while (str[i] && str[i] != c)
		i++;
	return (i - st);
}

static int	ft_scpy(char *dest, char *src, char c, int i)
{
	int k;

	k = 0;
	while (src[i] && src[i] != c)
	{
		dest[k] = src[i];
		k++;
		i++;
	}
	dest[k] = '\0';
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		a;

	i = 0;
	a = 0;
	if (!s ||
			!(tab = malloc(sizeof(char *) * (ft_strlen((char *)s) + 1))))
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			if (!(tab[a] = malloc(sizeof(char)
							* (ft_strlen_du_futur((char *)s, c, i) + 1))))
				return (NULL);
			i = ft_scpy(tab[a], (char *)s, c, i);
			a++;
		}
	}
	tab[a] = NULL;
	return (tab);
}

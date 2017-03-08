/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:26:30 by mhalit            #+#    #+#             */
/*   Updated: 2016/11/20 22:35:18 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_exceptions(int nb)
{
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nb == 0)
		return (ft_strdup("0"));
	return (NULL);
}

char			*ft_itoa(int nb)
{
	char	*r;
	int		tot;
	int		ret;
	int		a;

	a = 0;
	ret = 0;
	tot = nb;
	if (!(r = malloc(sizeof(char) * 15)))
		return (NULL);
	if (ft_exceptions(nb))
		return (ft_exceptions(nb));
	if (nb < 0)
		tot = -tot;
	while (tot)
	{
		ret = tot % 10;
		tot /= 10;
		r[a++] = ret + '0';
	}
	if (nb < 0)
		r[a++] = '-';
	r[a] = '\0';
	return (ft_strrev(r));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:49:35 by mhalit            #+#    #+#             */
/*   Updated: 2016/11/05 21:27:58 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int out;
	int signe;

	signe = 1;
	out = 0;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n' || *nptr == '\v' ||
*nptr == '\f' || *nptr == '\r')
		nptr++;
	if (*nptr == '-')
		signe = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9' && *nptr)
	{
		out = (out * 10) + (*nptr - 48);
		nptr++;
	}
	return (out * signe);
}

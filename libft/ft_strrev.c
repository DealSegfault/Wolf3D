/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 18:51:06 by mhalit            #+#    #+#             */
/*   Updated: 2016/11/20 20:01:30 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	tmp;

	tmp = 0;
	j = -1;
	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\0')
		i++;
	while (++j < --i)
	{
		tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
	}
	return (str);
}

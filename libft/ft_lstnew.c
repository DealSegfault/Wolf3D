/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 07:21:24 by mhalit            #+#    #+#             */
/*   Updated: 2016/11/21 22:46:00 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*out;

	if (!(out = malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		out->content = 0;
		out->content_size = 0;
	}
	else
	{
		if (!(out->content = malloc(sizeof(content) * content_size)))
			out->content = NULL;
		else
			ft_memcpy(out->content, content, content_size);
		out->content_size = content_size;
	}
	out->next = NULL;
	return (out);
}

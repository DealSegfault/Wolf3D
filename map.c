/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 06:17:17 by mhalit            #+#    #+#             */
/*   Updated: 2017/04/02 15:11:54 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int				escape(t_wolf *env)
{
	if (env)
		mlx_destroy_image(env->init, env->image);
	exit(42);
}

int				*sp_toi(char **line)
{
	int			*out;
	int			y;

	y = 0;
	while (line[y])
		y++;
	if (!(out = (int *)malloc(sizeof(int) * (y + 1))))
		return (NULL);
	y = 0;
	while (line[y])
		*out++ = ft_atoi(line[y++]);
	*out = '\0';
	out = out - y;
	return (out);
}

static void		free_split(char **str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int				load_map(t_wolf *env)
{
	int			fd;
	char		*line;
	char		**tmp;

	tmp = NULL;
	if (!(env->map = (int **)malloc(sizeof(int *) * MAPHEIGHT + 1)))
		return (0);
	if (!(fd = open("map", O_RDONLY)))
		return (0);
	while ((get_next_line(fd, &line)) > 0)
	{
		tmp = ft_strsplit(line, ' ');
		if (!(*(env->map)++ = sp_toi(tmp)))
			break ;
		free(line);
		free_split(tmp);
	}
	env->map = env->map - MAPHEIGHT;
	return (1);
}

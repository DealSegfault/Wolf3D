/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 21:59:38 by mhalit            #+#    #+#             */
/*   Updated: 2017/06/19 17:13:47 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		init_file(t_wolf *env)
{
	env->texture->file[0] = "pics/wood.xpm";
	env->texture->file[1] = "pics/redbrick.xpm";
	env->texture->file[2] = "pics/purplestone.xpm";
	env->texture->file[3] = "pics/colorstone.xpm";
	env->texture->file[4] = "pics/mossy.xpm";
}

int			init_text(t_wolf *data)
{
	int		i;

	i = 0;
	data->texture = malloc(sizeof(t_text) * 5);
	data->texture->file = malloc(sizeof(char *) * 6);
	init_file(data);
	while (i < 5)
	{
		data->texture[i].text.img = mlx_xpm_file_to_image(data->init,
		data->texture->file[i], &data->texture[i].text.width,
		&data->texture[i].text.height);
		if (data->texture[i].text.img == NULL)
			return (0);
		data->texture[i].text.data =
		mlx_get_data_addr(data->texture[i].text.img,
		&data->texture[i].text.bpp, &data->texture[i].text.size_l,
		&data->texture[i].text.endian);
		i++;
	}
	return (1);
}

int			get_texture_color(t_wolf *data, int id)
{
	int		index_text;
	int		ptr;

	index_text = (data->texy * data->texture[id].text.size_l) + (data->texx *
	data->texture[id].text.bpp / 8);
	ptr = *(int *)&data->texture[id].text.data[index_text];
	return (ptr);
}

void		mlx_text_to_img(t_wolf *env)
{
	env->id = env->map[env->mapx][env->mapy];
	if (env->id > 4)
		env->id = 0;
	if (env->side == 0)
		env->wallx = env->rayposy + env->perpwalldist * env->raydiry;
	else
		env->wallx = env->rayposx + env->perpwalldist * env->raydirx;
	env->wallx -= floor(env->wallx);
	env->texx = env->wallx * env->texture[env->id].text.width;
	if (env->side == 0 && env->raydirx > 0)
		env->texx = env->texture[env->id].text.width - env->texx - 1;
	if (env->side == 1 && env->raydiry < 0)
		env->texx = env->texture[env->id].text.width - env->texx - 1;
}

void		hud(t_wolf *env)
{
	char *px;
	char *py;

	px = ft_itoa((int)env->posx);
	py = ft_itoa((int)env->posy);
	mlx_string_put(env->init, env->win, 50, 50, 0xFFFFFF, "X/Y :");
	mlx_string_put(env->init, env->win, 50, 100, 0xFFFFFF, px);
	mlx_string_put(env->init, env->win, 50, 150, 0xFFFFFF, py);
	mlx_string_put(env->init, env->win, 50, 200, 0xFFFFFF,
	"NOCLIPON: / || OFF: *");
	mlx_string_put(env->init, env->win, 50, 250, 0xFFFFFF,
	"SPAWN : + || MEMORY: -");
	free(py);
	free(px);
}

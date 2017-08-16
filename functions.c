/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 18:33:28 by mhalit            #+#    #+#             */
/*   Updated: 2017/06/19 17:37:11 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		w_init(t_wolf *env, int x)
{
	env->camerax = 2 * x / (double)env->lar - 1;
	env->rayposx = env->posx;
	env->rayposy = env->posy;
	env->raydirx = env->dirx + env->planex * env->camerax;
	env->raydiry = env->diry + env->planey * env->camerax;
	env->mapx = env->rayposx;
	env->mapy = env->rayposy;
	env->deltadistx = sqrt(1 + (env->raydiry * env->raydiry) /
	(env->raydirx * env->raydirx));
	env->deltadisty = sqrt(1 + (env->raydirx * env->raydirx) /
	(env->raydiry * env->raydiry));
	env->hit = 0;
}

void		w_step(t_wolf *env)
{
	if (env->raydirx < 0)
	{
		env->stepx = -1;
		env->sidedistx = (env->rayposx - env->mapx) * env->deltadistx;
	}
	else
	{
		env->stepx = 1;
		env->sidedistx = (env->mapx + 1.0 - env->rayposx) * env->deltadistx;
	}
	if (env->raydiry < 0)
	{
		env->stepy = -1;
		env->sidedisty = (env->rayposy - env->mapy) * env->deltadisty;
	}
	else
	{
		env->stepy = 1;
		env->sidedisty = (env->mapy + 1.0 - env->rayposy) * env->deltadisty;
	}
}

void		w_wall(t_wolf *env)
{
	while (env->hit == 0)
	{
		if (env->sidedistx < env->sidedisty)
		{
			env->sidedistx += env->deltadistx;
			env->mapx += env->stepx;
			env->side = 0;
		}
		else
		{
			env->sidedisty += env->deltadisty;
			env->mapy += env->stepy;
			env->side = 1;
		}
		if (env->mapx < 0 || env->mapy < 0)
		{
			env->mapx = env->mapx % 4200;
			env->mapy = env->mapy % 4200;
		}
		env->hit = (env->map[env->mapx][env->mapy] > 0 ? 1 : 0);
	}
}

void		w_stripe(t_wolf *env)
{
	if (env->side == 0)
		env->perpwalldist = (env->mapx - env->rayposx +
		(1 - env->stepx) / 2) / env->raydirx;
	else
		env->perpwalldist = (env->mapy - env->rayposy +
		(1 - env->stepy) / 2) / env->raydiry;
	env->lineheight = (int)(env->hau / env->perpwalldist);
	env->drawstart = -env->lineheight / 2 + env->hau / 2;
	if (env->drawstart < 0)
		env->drawstart = 0;
	env->drawend = env->lineheight / 2 + env->hau / 2;
	if (env->drawend >= env->hau)
		env->drawend = env->hau - 1;
}

void		w_draw(t_wolf *env, int x)
{
	int		y;
	int		pixel;
	int		d;

	y = 0;
	while (y < env->drawstart - 1)
	{
		mlx_pixel_image(x, y, env, 0xD3D3D3);
		y++;
	}
	mlx_text_to_img(env);
	env->id > 4 ? env->id = 0 : 0;
	while (y < env->drawend - 1)
	{
		d = y * 256 - env->hau * 128 + env->lineheight * 128;
		env->texy = (((d * env->texture[env->id].text.width) /
		env->lineheight) / 256);
		pixel = get_texture_color(env, env->id);
		mlx_pixel_image(x, y++, env, pixel);
	}
	while (y < env->hau - 1)
	{
		mlx_pixel_image(x, y, env, 0x808080);
		y++;
	}
}

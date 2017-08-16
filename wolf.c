/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 19:24:56 by mhalit            #+#    #+#             */
/*   Updated: 2017/06/19 17:22:05 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		mlx_pixel_image(int x, int y, t_wolf *env, int color)
{
	long	pos;

	pos = (x * env->bpp / 8) + (y * env->size_l);
	pos = pos < 0 ? -pos : pos;
	pos = pos % 11063993;
	env->data[pos] = color;
	env->data[pos + 1] = color >> 8;
	env->data[pos + 2] = color >> 16;
}

int			wolf3d(t_wolf *env)
{
	int		x;

	env->image = mlx_new_image(env->init, env->lar, env->hau);
	env->data = mlx_get_data_addr(env->image, &env->bpp,
	&env->size_l, &env->endian);
	x = 0;
	while (x < env->lar - 1)
	{
		w_init(env, x);
		w_step(env);
		w_wall(env);
		w_stripe(env);
		w_draw(env, x);
		x++;
	}
	mlx_put_image_to_window(env->init, env->win, env->image, 0, 0);
	hud(env);
	return (0);
}

int			init(t_wolf *env)
{
	env->movespeed = 0.30;
	env->rotspeed = 0.25;
	env->lar = 2000;
	env->hau = 1384;
	env->init = mlx_init();
	env->win = mlx_new_window(env->init, env->lar, env->hau, "Wolf3D");
	env->posx = 10.2;
	env->posy = 10.2;
	env->dirx = -1;
	env->diry = 0;
	env->planex = 0;
	env->planey = 0.66;
	env->time = 1;
	env->noclip = 0;
	if (!(env->map = map()) || !init_text(env))
		return (0);
	return (1);
}

int			main(int argc, char **argv)
{
	t_wolf	*env;

	if (argc == 1 && argv)
	{
		if (!(env = malloc(sizeof(t_wolf))))
			return (0);
		if (!init(env))
			return (0);
		wolf3d(env);
		mlx_key_hook(env->win, khook, env);
		mlx_hook(env->win, 17, 0, escape, env);
		mlx_hook(env->win, 2, 0, khook, env);
		mlx_loop(env->init);
	}
	return (0);
}

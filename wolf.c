/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 19:24:56 by mhalit            #+#    #+#             */
/*   Updated: 2017/04/02 15:10:37 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		w_color(t_wolf *env)
{
	if (env->map[env->mapx][env->mapy] == 0)
		env->color = YELLOW;
	if (env->map[env->mapx][env->mapy] == 1)
		env->color = RED;
	if (env->map[env->mapx][env->mapy] == 2)
		env->color = GREEN;
	if (env->map[env->mapx][env->mapy] == 3)
		env->color = BLUE;
	if (env->map[env->mapx][env->mapy] == 4)
		env->color = WHITE;
	if (env->side == 1)
		env->color /= 2;
}

void		mlx_pixel_image(int x, int y, t_wolf *env, int color)
{
	int pos;

	pos = (x * env->bpp / 8) + (y * env->size_l);
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
	while (x < env->lar)
	{
		w_init(env, x);
		w_step(env);
		w_wall(env);
		w_stripe(env);
		w_color(env);
		w_draw(env, x);
		x++;
	}
	mlx_put_image_to_window(env->init, env->win, env->image, 0, 0);
	return (0);
}

void		init(t_wolf *env)
{
	env->lar = 2000;
	env->hau = 1384;
	env->init = mlx_init();
	env->win = mlx_new_window(env->init, env->lar, env->hau, "Wolf3D");
	env->posx = 22;
	env->posy = 12;
	env->dirx = -1;
	env->diry = 0;
	env->planex = 0;
	env->planey = 0.66;
	env->time = 1;
	if (!load_map(env))
	{
		ft_putstr("Erreur Map");
		exit(42);
	}
}

int			main(int argc, char **argv)
{
	t_wolf	*env;

	if (argc == 1 && argv)
	{
		if (!(env = malloc(sizeof(t_wolf))))
			return (0);
		init(env);
		wolf3d(env);
		mlx_key_hook(env->win, khook, env);
		mlx_hook(env->win, 17, 0, escape, env);
		mlx_loop(env->init);
	}
	return (0);
}

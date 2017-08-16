/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 02:24:35 by mhalit            #+#    #+#             */
/*   Updated: 2017/06/11 02:24:38 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	left(t_wolf *env)
{
	env->olddirx = env->dirx;
	env->dirx = env->dirx * cos(env->rotspeed) - env->diry *
	sin(env->rotspeed);
	env->diry = env->olddirx * sin(env->rotspeed) + env->diry *
	cos(env->rotspeed);
	env->oldplanex = env->planex;
	env->planex = env->planex * cos(env->rotspeed) - env->planey *
	sin(env->rotspeed);
	env->planey = env->oldplanex * sin(env->rotspeed) + env->planey *
	cos(env->rotspeed);
}

static void	right(t_wolf *env)
{
	env->olddirx = env->dirx;
	env->dirx = env->dirx * cos(-env->rotspeed) - env->diry *
	sin(-env->rotspeed);
	env->diry = env->olddirx * sin(-env->rotspeed) + env->diry *
	cos(-env->rotspeed);
	env->oldplanex = env->planex;
	env->planex = env->planex * cos(-env->rotspeed) - env->planey *
	sin(-env->rotspeed);
	env->planey = env->oldplanex * sin(-env->rotspeed) + env->planey *
	cos(-env->rotspeed);
}

static void	up(t_wolf *env)
{
	if (!env->map[(int)(env->posx + env->dirx *
		env->movespeed)][(int)(env->posy)] || env->noclip == 1)
		env->posx += env->dirx * env->movespeed;
	if (!env->map[(int)(env->posx)][(int)(env->posy +
		env->diry * env->movespeed)] || env->noclip == 1)
		env->posy += env->diry * env->movespeed;
}

static void	down(t_wolf *env)
{
	if (!env->map[(int)(env->posx - env->dirx *
		env->movespeed)][(int)(env->posy)] || env->noclip == 1)
		env->posx -= env->dirx * env->movespeed;
	if (!env->map[(int)(env->posx)][(int)(env->posy -
		env->diry * env->movespeed)] || env->noclip == 1)
		env->posy -= env->diry * env->movespeed;
}

int			khook(int keycode, t_wolf *env)
{
	if (keycode == 53)
		exit(42);
	if (keycode == RIGHT)
		right(env);
	else if (keycode == LEFT)
		left(env);
	else if (keycode == UP)
		up(env);
	else if (keycode == DOWN)
		down(env);
	else if (keycode == NOCLIPON || keycode == NOCLIPOFF)
		env->noclip = (keycode == NOCLIPON ? 1 : 0);
	else if (keycode == MINUS || keycode == PLUS)
	{
		env->posx = (keycode == MINUS ? -400.4 : 11.2);
		env->posy = (keycode == MINUS ? -400.4 : 11.2);
	}
	else
		return (0);
	mlx_destroy_image(env->init, env->image);
	wolf3d(env);
	return (0);
}

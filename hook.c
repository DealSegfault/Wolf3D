/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 05:55:06 by mhalit            #+#    #+#             */
/*   Updated: 2017/04/02 14:44:32 by mhalit           ###   ########.fr       */
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
		env->movespeed)][(int)(env->posy)])
		env->posx += env->dirx * env->movespeed;
	if (!env->map[(int)(env->posx)][(int)(env->posy +
		env->diry * env->movespeed)])
		env->posy += env->diry * env->movespeed;
}

static void	down(t_wolf *env)
{
	if (!env->map[(int)(env->posx - env->dirx *
		env->movespeed)][(int)env->posy])
		env->posx -= env->dirx * env->movespeed;
	if (!env->map[(int)(env->posx)][(int)(env->posy -
		env->diry * env->movespeed)])
		env->posy -= env->diry * env->movespeed;
}

int			khook(int keycode, t_wolf *env)
{
	env->movespeed = 0.25;
	env->rotspeed = 0.25;
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
	else
		return (0);
	mlx_destroy_image(env->init, env->image);
	wolf3d(env);
	return (0);
}

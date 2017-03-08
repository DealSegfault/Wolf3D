/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 19:24:56 by mhalit            #+#    #+#             */
/*   Updated: 2017/02/25 19:27:39 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		w_init(t_wolf *env, int x)
{
	env->cameraX = 2 * x / (double)env->lar - 1;
	env->rayPosX = env->posX;
	env->rayPosY = env->posY;
	env->rayDirX = env->dirX + env->planeX * env->cameraX;
	env->rayDirY = env->dirY + env->planeY * env->cameraX;
	env->mapX = env->rayPosX;
	env->mapY = env->rayPosY;
	env->deltaDistX = sqrt(1 + (env->rayDirY * env->rayDirY) / (env->rayDirX * env->rayDirX));
	env->deltaDistY = sqrt(1 + (env->rayDirX * env->rayDirX) / (env->rayDirY * env->rayDirY));
	env->hit = 0;	
}

void		w_step(t_wolf *env)
{
	if (env->rayDirX < 0)
    {
    	env->stepX = -1;
    	env->sideDistX = (env->rayPosX - env->mapX) * env->deltaDistX;
    }
	else
	{
	env->stepX = 1;
	env->sideDistX = (env->mapX + 1.0 - env->rayPosX) * env->deltaDistX;
	}
	if (env->rayDirY < 0)
	{
	env->stepY = -1;
	env->sideDistY = (env->rayPosY - env->mapY) * env->deltaDistY;
	}
	else
	{
	env->stepY = 1;
	env->sideDistY = (env->mapY + 1.0 - env->rayPosY) * env->deltaDistY;
	}
}

void		w_wall(t_wolf *env)
{
	while (env->hit == 0)
	{
		if (env->sideDistX < env->sideDistY)
		{
			env->sideDistX += env->deltaDistX;
			env->mapX += env->stepX;
			env->side = 0;
		}
		else
		{
			env->sideDistY += env->deltaDistY;
			env->mapY += env->stepY;
			env->side = 1;
		}
		env->hit = (env->map[env->mapX][env->mapY] > 0 ? 1 : 0);
	}
}

void		w_stripe(t_wolf *env)
{	
	//printf("%lf:%lf:%lf:%lf:%lf:%lf\n", env->side, );
	ft_putchar('=');
	if (env->side == 0)
		env->perpWallDist = (env->mapX - env->rayPosX + (1 - env->stepX) / 2) / env->rayDirX;
	else
		env->perpWallDist = (env->mapY - env->rayPosY + (1 - env->stepY) / 2) / env->rayDirY;
	env->lineHeight = (int)(env->hau / env->perpWallDist);
	env->drawStart = -env->lineHeight / 2 + env->hau / 2;
	if (env->drawStart < 0)
		env->drawStart = 0;
	env->drawEnd = env->lineHeight / 2 + env->hau / 2;
	if (env->drawEnd >= env->hau)
		env->drawEnd = env->hau - 1;
}

void		w_color(t_wolf *env)
{
	if (env->map[env->mapX][env->mapY] == 0)
		env->color = YELLOW;
	if (env->map[env->mapX][env->mapY] == 1)
		env->color = RED;
	if (env->map[env->mapX][env->mapY] == 2)
		env->color = GREEN;
	if (env->map[env->mapX][env->mapY] == 3)
		env->color = BLUE;
	if (env->map[env->mapX][env->mapY] == 4)
		env->color = WHITE;
	if (env->side == 1)
		env->color /= 2;
}

void		w_draw(t_wolf *env, int x)
{
	int pos;
	int y;

	y = env->drawStart;
	while (y < env->drawEnd)
	{
		pos = (x * env->bpp / 8) + (y * env->size_l);
		env->data[pos] = env->color;
		env->data[pos + 1] = env->color >> 8;
		env->data[pos + 2] = env->color >> 16;
		y++;
	}
}

int			wolf3d(t_wolf *env)
{
	int 	x;

	env->image = mlx_new_image(env->init, env->lar, env->hau);
	env->data = mlx_get_data_addr(env->image, &env->bpp, &env->size_l, &env->endian);
	x = 0;
	while (x < env->lar)
	{
		w_init(env, x);		
		w_step(env);
		w_wall(env);
		w_stripe(env);
		w_color(env);
		w_draw(env, x);
		ft_putchar('\n');
		x++;
	}
	env->otime = env->time / CLOCKS_PER_SEC;
	env->time = clock();
	env->frameTime = (env->time  - env->otime) / 1000;
	printf("%lf\n", env->frameTime);
	mlx_put_image_to_window(env->init, env->win, env->image, 0, 0);
	return (0);
}

void		init(t_wolf *env)
{
	env->lar = 2000;
	env->hau = 1384;
	env->init = mlx_init();
	env->win = mlx_new_window(env->init, env->lar, env->hau, "Wolf3D");
	
	env->posX = 22;
	env->posY = 12;
	env->dirX = -1;
	env->dirY = 0;
	env->planeX = 0;
	env->planeY = 0.66;
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
		mlx_loop(env->init);
	}
	return (0);
}

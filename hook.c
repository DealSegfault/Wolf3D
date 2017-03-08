/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 05:55:06 by mhalit            #+#    #+#             */
/*   Updated: 2017/03/07 05:55:24 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		khook(int keycode, t_wolf *env)
{	
	env->moveSpeed = 0.25;//env->frameTime * 5.0;
	env->rotSpeed = 0.25;//env->frameTime * 3.0;

	printf("%lf : %lf : %lf\n", env->posX, env->dirX, env->moveSpeed);
	if (keycode == RIGHT)
	{
		env->oldDirX = env->dirX;
		env->dirX = env->dirX * cos(-env->rotSpeed) - env->dirY * sin(-env->rotSpeed);
      	env->dirY = env->oldDirX * sin(-env->rotSpeed) + env->dirY * cos(-env->rotSpeed);
      	env->oldPlaneX = env->planeX;
     	env->planeX = env->planeX * cos(-env->rotSpeed) - env->planeY * sin(-env->rotSpeed);
      	env->planeY = env->oldPlaneX * sin(-env->rotSpeed) + env->planeY * cos(-env->rotSpeed);
	}
	else if (keycode == LEFT)
	{
		env->oldDirX = env->dirX;
		env->dirX = env->dirX * cos(env->rotSpeed) - env->dirY * sin(env->rotSpeed);
      	env->dirY = env->oldDirX * sin(env->rotSpeed) + env->dirY * cos(env->rotSpeed);
      	env->oldPlaneX = env->planeX;
     	env->planeX = env->planeX * cos(env->rotSpeed) - env->planeY * sin(env->rotSpeed);
      	env->planeY = env->oldPlaneX * sin(env->rotSpeed) + env->planeY * cos(env->rotSpeed);
	}
	else if (keycode == UP)
    {
      if (!env->map[(int)(env->posX + env->dirX * env->moveSpeed)][(int)(env->posY)]) 
      	env->posX += env->dirX * env->moveSpeed;
      if (!env->map[(int)(env->posX)][(int)(env->posY + env->dirY * env->moveSpeed)]) 
      	env->posY += env->dirY * env->moveSpeed;
    }
    else if (keycode == DOWN)
    {
      if (!env->map[(int)(env->posX - env->dirX * env->moveSpeed)][(int)env->posY]) 
      	env->posX -= env->dirX * env->moveSpeed;
      if (!env->map[(int)(env->posX)][(int)(env->posY - env->dirY * env->moveSpeed)]) 
      	env->posY -= env->dirY * env->moveSpeed;
    }
	else
		return (0);
	mlx_destroy_image(env->init, env->image);
	wolf3d(env);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 19:16:56 by mhalit            #+#    #+#             */
/*   Updated: 2017/02/25 19:24:45 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <math.h>
# include <time.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

# define MAPWIDTH 24
# define MAPHEIGHT 24
# define RED 0x8b0000
# define BLUE 0x00ffff
# define GREEN 0xFF00
# define WHITE 0xffffff
# define YELLOW 0xffa500
# define BLACK 0x000000

# define MOTION 6
# define MASK (1L<<6)
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define IP 81
# define IM 75
# define M_UP 5
# define M_DOWN 4
# define M_LEFT 7
# define M_RIGHT 6
# define PLUS 69
# define MINUS 78
# define PAUSE 35

typedef struct	s_wolf
{
	int			**map;
	int			hau;
	int			lar;
	void		*init;
	void		*win;
	void		*image;
	char		*data;
	int			bpp;
	int			size_l;
	int			endian;
	int			color;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		olddirx;
	double		oldplanex;
	double		planex;
	double		planey;
	double		camerax;
	double		rayposx;
	double		rayposy;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;

	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	double		otime;
	double		time;
	double		movespeed;
	double		rotspeed;
	double		frametime;
}				t_wolf;

void			init(t_wolf *env);
int				wolf3d(t_wolf *env);
void			w_color(t_wolf *env);
int				khook(int keycode, t_wolf *env);
void			w_init(t_wolf *env, int x);
void			w_step(t_wolf *env);
void			w_stripe(t_wolf *env);
void			w_draw(t_wolf *env, int x);
void			w_wall(t_wolf *env);
int				*sp_toi(char **line);
int				load_map(t_wolf *env);
void			mlx_pixel_image(int x, int y, t_wolf *env, int color);
#endif

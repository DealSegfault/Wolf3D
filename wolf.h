/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:13:10 by mhalit            #+#    #+#             */
/*   Updated: 2017/06/19 17:13:12 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <math.h>
# include <time.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

# define MAPWIDTH 22
# define MAPHEIGHT 22
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
# define NOCLIPON 75
# define NOCLIPOFF 67
# define IP 81
# define IM 75
# define M_UP 5
# define M_DOWN 4
# define M_LEFT 7
# define M_RIGHT 6
# define PLUS 69
# define MINUS 78
# define PAUSE 35
# define TEXTWIDTH 64
# define TEXTHEIGHT 64

typedef struct	s_img
{
	void		*img;
	char		*data;
	int			bpp;
	int			size_l;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct	s_text
{
	t_img		text;
	char		**file;
	int			current;
}				t_text;

typedef struct	s_wolf
{
	int			(*map)[22];
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
	double		wallx;
	int			texx;
	int			texy;
	int			id;
	int			noclip;
	t_text		*texture;
}				t_wolf;

int				init(t_wolf *env);
int				wolf3d(t_wolf *env);
void			w_color(t_wolf *env);
int				khook(int keycode, t_wolf *env);
int				escape(t_wolf *env);
void			w_init(t_wolf *env, int x);
void			w_step(t_wolf *env);
void			w_stripe(t_wolf *env);
void			w_draw(t_wolf *env, int x);
void			w_wall(t_wolf *env);
void			mlx_pixel_image(int x, int y, t_wolf *env, int color);
void			press(int keycode, t_wolf *env);
void			texture(t_wolf *env, char **img);
void			mlx_text_to_img(t_wolf *env);
int				get_texture_color(t_wolf *data, int id);
int				init_text(t_wolf *data);
void			*map(void);
void			hud(t_wolf *env);
#endif

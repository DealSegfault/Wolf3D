/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 16:01:58 by mhalit            #+#    #+#             */
/*   Updated: 2017/03/17 18:15:19 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	main()
{
	void	*init = mlx_init();
	void	*win = mlx_new_window(init, 1000, 1000, "Test");
	int  	bpp;
	int 	endian;
	int 	size_l;


	void	*image = mlx_new_image(init, 1000, 1000);
	char 	*data = mlx_get_data_addr(image, &bpp, &size_l, &endian);

	int x = 0;
	int y = 0;
	int pos;
	int color = 4042;
	while (y < 100)
	{
		x = 0;
		while (x < 100)
		{
			pos = x * 4 + y * size_l;
			data[pos] = color;
			data[pos + 1] = color >> 8;
			data[pos + 2] = color >> 16;
			x++;
		}
		y++;
	}
	
	void	*image2 = mlx_new_image(init, 1000, 1000);
	char 	*data2 = mlx_get_data_addr(image2, &bpp, &size_l, &endian);

	x = 100;
 	y = 100;
	while (y < 200)
	{
		x = 100;
		while (x < 200)
		{
			pos = x * 4 + y * size_l;
			data2[pos] = color;
			data2[pos + 1] = color >> 8;
			data2[pos + 2] = color >> 16;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(init, win, image2, 0, 0);
	mlx_put_image_to_window(init, win, image, 0, 0);
	mlx_loop(init);
}

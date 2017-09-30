/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:43:10 by atyrode           #+#    #+#             */
/*   Updated: 2017/10/01 00:36:45 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

void		calc_julia(t_mlx *mlx)
{
	int		i;
	double		tmp;

	COORD_X = 0;
	while (COORD_X < IMAGE_X)
	{
		COORD_Y = 0;
		while (COORD_Y < IMAGE_Y)
		{
			C_R = 0.285;
			C_I = 0.01;
			Z_R = COORD_X / ZOOM + X1;
			Z_I = COORD_Y / ZOOM + Y1;
			i = 0;

			while ((Z_R * Z_R + Z_I * Z_I) < 4 && i < I_MAX)
			{
				tmp = Z_R;
				Z_R = Z_R * Z_R - Z_I * Z_I + C_R;
				Z_I = 2 * Z_I * tmp + C_I;
				i++;
			}
			if (i == I_MAX)
			{
				COLOR = 0x00000000;
				image_set_pixel(mlx);
			}
			else
			{
				COLOR = get_rvb(i * 255 / I_MAX, 0, 0);
				image_set_pixel(mlx);
			}
			COORD_Y++;
		}
		COORD_X++;
	}
	return ;
}

void		print_julia(t_mlx *mlx)
{
	X1 = -2.1;
	X2 = 0.6;
	Y1 = -1.2;
	Y2 = 1.2;
	I_MAX = 50;
	ZOOM = 300;

	IMAGE_X = (X2 - X1) * ZOOM;
	IMAGE_Y = (Y2 - Y1) * ZOOM;
	calc_julia(mlx);
	return ;
}

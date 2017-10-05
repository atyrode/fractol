/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newjuliabrot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <atyrode@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:43:36 by atyrode           #+#    #+#             */
/*   Updated: 2017/10/05 20:33:35 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

#ifndef GPU

void		mandelbrot(t_mlx *mlx)
{
	C_X = ((double)COORD_X - CENTER_X) / ZOOM_X + X1 + OFFSETX;
	C_Y = ((double)CENTER_Y - COORD_Y) / ZOOM_Y + Y1 + OFFSETY;
	Z_X = 0;
	Z_Y = 0;
	I = 0;
	while ((Z_X * Z_X + Z_Y * Z_Y) < 4.0 && I < I_MAX)
	{
		TMP = Z_X;
		Z_X = Z_X * Z_X - Z_Y * Z_Y + C_X;
		Z_Y = 2.0 * Z_Y * TMP + C_Y;
		I++;
	}
	mlx->r->z = Z_X * Z_X + Z_Y * Z_Y;
	if (mlx->r->z > 4.0)
		mlx->r->z = 4.0;
	if (mlx->r->z < 0.0)
		mlx->r->z = 0.0;
	mlx->r->color = 0;
}

void		julia(t_mlx *mlx)
{
	Z_X = ((double)COORD_X - CENTER_X) / ZOOM_X + X1 + OFFSETX;
	Z_Y = ((double)CENTER_Y - COORD_Y) / ZOOM_Y + Y1 + OFFSETY;
	C_X = (double)MOUSE_X / 1000 - 1;
	C_Y = (double)MOUSE_Y / 400 - 1;
	I = 0;
	while ((Z_X * Z_X + Z_Y * Z_Y) < 4.0 && I < I_MAX)
	{
		TMP = Z_X;
		Z_X = Z_X * Z_X - Z_Y * Z_Y + C_X;
		Z_Y = 2.0 * Z_Y * TMP + C_Y;
		I++;
	}
	mlx->r->z = Z_X * Z_X + Z_Y * Z_Y;
	if (mlx->r->z > 4.0)
		mlx->r->z = 4.0;
	if (mlx->r->z < 0.0)
		mlx->r->z = 0.0;
	mlx->r->color = 0;
}

void		newton(t_mlx *mlx)
{
	double 	dd;

	C_X = ((double)COORD_X - CENTER_X) / ZOOM_X + X1 + OFFSETX;
	C_Y = ((double)CENTER_Y - COORD_Y) / ZOOM_Y + Y1 + OFFSETY;
	I = 0;
	while (I < I_MAX)
	{
		Z_X = C_X * C_X;
		Z_Y = C_Y * C_Y;
		dd = 3.0 * ((Z_X - Z_Y) * (Z_X - Z_Y) + 4.0 * Z_X * Z_Y);
		if (dd == 0.0)
			dd = 0.000001;
		TMP = C_X;
		C_X = (2.0 / 3.0) * C_X + (Z_X - Z_Y) / dd;
		C_Y = (2.0 / 3.0) * C_Y - 2.0 * TMP * C_Y / dd;
		I++;
	}
	//mlx->r->color = get_color_indicator(C_X, C_Y, I);
	//mlx->r->r = clamp_to_pct4(C_X, -5., 1.5);
}

/*void		colors(t_mlx *mlx)
{

}*/

void		fractals(t_mlx *mlx)
{
	COORD_X = 0;
	while (COORD_X < W_WIDTH)
	{
		COORD_Y = 0;
		while (COORD_Y < W_HEIGHT)
		{
			if (FRAC == 0)
				mandelbrot(mlx);
			else
				(FRAC == 1) ? julia(mlx) : newton(mlx);
			if (I == I_MAX)
			{
				COLOR = 0x00000000;
				image_set_pixel(mlx);
			}
			else
			{
				COLOR = get_rvb(I * 255 / I_MAX, 0, 0);
				image_set_pixel(mlx);
			}
			COORD_Y++;
		}
		COORD_X++;
	}
	return ;
}

#else
#endif

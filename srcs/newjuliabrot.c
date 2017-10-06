/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newjuliabrot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <atyrode@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:43:36 by atyrode           #+#    #+#             */
/*   Updated: 2017/10/06 14:52:41 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

#ifndef GPU

void		mandelbrot(t_mlx *mlx)
{
	//printf ("ZOOM_X %f | ZOOM_Y %f", ZOOM_X, ZOOM_Y);
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
	mlx->r->color = get_color_indicator(C_X, C_Y, I);
	mlx->r->z = clamp_to_pct4(C_X, -5., 1.5);
}

void		colors(t_mlx *mlx)
{
	COLOR = 0;
	switch(mlx->env->col_n)
	{
		case 1:
			COLOR = color1(*mlx->r, mlx->mandelbrot->i_max);
			break ;
		case 2:
			COLOR = color2(*mlx->r, mlx->mandelbrot->i_max);
			break ;
		case 3:
			COLOR = color3(*mlx->r, mlx->mandelbrot->i_max);
			break ;
		case 4:
			COLOR = color4(*mlx->r, mlx->mandelbrot->i_max);
			break ;
		case 5:
			COLOR = color5(*mlx->r, mlx->mandelbrot->i_max);
			break ;
		case 6:
			COLOR = color6_2(*mlx->r);
			break ;
	}
}

void		fractals(t_mlx *mlx)
{
	mlx->env->d_zoom_x = mlx->env->zoom_x * W_WIDTH / (X2 - X1);
	mlx->env->d_zoom_y = mlx->env->zoom_y * W_HEIGHT / (Y2 - Y1);
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
			/*if (I == I_MAX)
			{
				//printf ("black!\n");
				COLOR = 0x000000;
				image_set_pixel(mlx);
			}
			else
			{
				//printf ("color!\n");
				COLOR = get_rvb(I * 255 / I_MAX, 0, 0);*/
				colors(mlx);
				image_set_pixel(mlx);
			//}
			COORD_Y++;
		}
		COORD_X++;
	}
	return ;
}

#else
#endif

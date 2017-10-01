/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:43:36 by atyrode           #+#    #+#             */
/*   Updated: 2017/10/01 23:02:56 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

double interpolate(double start, double end, double interpolation)
{
	return start + ((end - start) * interpolation);
}

void applyZoom(t_mlx *mlx, double mouseX, double mouseY, double zoomFactor)
{
	double interpolation;
	
	interpolation = 1.0 / zoomFactor;
	X1 = interpolate(mouseY, X1, interpolation);
	Y1 = interpolate(mouseX, Y1, interpolation);
	X2 = interpolate(mouseY, X2, interpolation);
	Y2 = interpolate(mouseX, Y2, interpolation);
}

void		re_calc_mandel(t_mlx *mlx, int x, int y)
{
	double mouseX;
	double mouseY;

	mouseX = (double)x / (W_WIDTH / (X2 - X1)) + X1;
	mouseY = (double)y / (W_HEIGHT / (Y2 - Y1)) + Y1;
	applyZoom(mlx, mouseX, mouseY, ZOOM);
	test_func(1, 0, mlx);
	calc_mandel(mlx);

}

void		calc_mandel(t_mlx *mlx)
{
	int		i;

	printf ("test2\n");

	COORD_X = 0;
	while (COORD_X < W_WIDTH)
	{
		COORD_Y = 0;
		while (COORD_Y < W_HEIGHT)
		{
			if (FRAC == 0)
			{
				C_X = (double)COORD_X / (W_WIDTH / (X2 - X1)) + X1;
				C_Y = (double)COORD_Y / (W_HEIGHT / (Y2 - Y1)) + Y1;
				Z_X = 0;
				Z_Y = 0;
			}
			else if (FRAC == 1)
			{
				Z_X = (double)COORD_X / (W_WIDTH / (X2 - X1)) + X1;
				Z_Y = (double)COORD_Y / (W_HEIGHT / (Y2 - Y1)) + Y1;
			}
			i = 0;
			while ((Z_X * Z_X + Z_Y * Z_Y) < 4 && i < I_MAX)
			{
				SQZ_X = Z_X * Z_X;
				SQZ_Y = Z_Y * Z_Y;
				Z_Y = 2 * Z_Y * Z_X + C_Y;
				Z_X = SQZ_X - SQZ_Y + C_X;
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

void		print_mandelbrot(t_mlx *mlx)
{
	X1 = -2.1;
	X2 = 0.6;
	Y1 = -1.2;
	Y2 = 1.2;
	I_MAX = 100;

	calc_mandel(mlx);
	return ;
}

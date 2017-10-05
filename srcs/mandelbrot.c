/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <atyrode@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:43:36 by atyrode           #+#    #+#             */
/*   Updated: 2017/10/05 15:30:59 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

double	interpolate(double start, double end, double interp, t_mlx *mlx)
{
	return (start + ((end - start) * ((BUTTON == 1) ? interp : 1 / interp)));
}

void	apply_zoom(t_mlx *mlx, double mousex, double mousey, double zoomfactor)
{
	double	interpolation;

	interpolation = 1.0 / zoomfactor;
	X1 = interpolate(mousex, X1, interpolation, mlx);
	Y1 = interpolate(mousey, Y1, interpolation, mlx);
	X2 = interpolate(mousex, X2, interpolation, mlx);
	Y2 = interpolate(mousey, Y2, interpolation, mlx);
}

void	re_calc_mandel(t_mlx *mlx, int x, int y)
{
	double mousex;
	double mousey;

	mousex = (double)x / (W_WIDTH / (X2 - X1)) + X1;
	mousey = (double)y / (W_HEIGHT / (Y2 - Y1)) + Y1;
	apply_zoom(mlx, mousex, mousey, ZOOM);
	calc_mandel(mlx);
}

int		set_mandel_val(t_mlx *mlx, int i)
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
	return (i);
}

void	calc_mandel(t_mlx *mlx)
{
	int		i;

	COORD_X = 0;
	while (COORD_X < W_WIDTH)
	{
		COORD_Y = 0;
		while (COORD_Y < W_HEIGHT)
		{
			i = set_mandel_val(mlx, i);
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

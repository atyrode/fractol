/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <atyrode@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:41:51 by atyrode           #+#    #+#             */
/*   Updated: 2017/10/06 16:00:39 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

void	set_zoom_center(t_mlx *mlx, int x, int y)
{
	OFFSETX += OFFSETX_SHRINK((mlx->env->center_x - x) / mlx->env->zoom_x);
	OFFSETY += OFFSETY_SHRINK((mlx->env->center_y - y) / mlx->env->zoom_y);
	mlx->env->center_x = x;
	mlx->env->center_y = y;
}

void	de_zoom(t_mlx *mlx, int i, double j)
{
	mlx->env->show_center = 0;
	set_zoom_center(mlx, X, Y);
	mlx->env->zoom_x = (i == 1) ? mlx->env->zoom_x * j : mlx->env->zoom_x / j;
	mlx->env->zoom_y = (i == 1) ? mlx->env->zoom_y * j : mlx->env->zoom_y / j;
	mlx->mandelbrot->i_max_temp++;
	if (mlx->mandelbrot->i_max_temp++ > 5)
	{
		mlx->mandelbrot->i_max_temp = 0;
		mlx->mandelbrot->i_max += i;
	}
	redraw_fractal(mlx);
	set_zoom_center(mlx, W_WIDTH / 2, W_HEIGHT / 2);
}

void	init_frac_values(t_mlx *mlx)
{
	mlx->env->mouse_stopped = 0;
	mlx->mandelbrot->i_max_temp = 0;
	COORD_X = 0;
	COORD_Y = 0;
	I_MAX = 100;
	X1 = -2.1;
	X2 = 0.6;
	Y1 = -1.2;
	Y2 = 1.2;
	mlx->env->zoom_x = 1;
	mlx->env->zoom_y = 1;
	mlx->env->center_x = W_WIDTH / 2;
	mlx->env->center_y = W_HEIGHT / 2;
	mlx->env->offset_x = (FRAC == 1) ? 2.1 : OFFSETX_SHRINK(-W_WIDTH / 2);
	mlx->env->offset_y = OFFSETY_SHRINK(W_HEIGHT / 2);
	mlx->env->mouse_x = 1000;
	mlx->env->mouse_y = 398;
	mlx->env->mouse_stopped = 0;
	if (mlx->init == 1)
		redraw_fractal(mlx);
}

int		get_rvb(int red, int green, int blue)
{
	int r;
	int g;
	int b;

	r = red & 0xFF;
	g = green & 0xFF;
	b = blue & 0xFF;
	return (r << 16 | g << 8 | b);
}

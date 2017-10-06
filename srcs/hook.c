/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <atyrode@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 15:27:01 by atyrode           #+#    #+#             */
/*   Updated: 2017/10/06 14:28:48 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

void		hooks(t_mlx *mlx)
{
	mlx_mouse_hook(mlx->win, mouse_hook, mlx);
	mlx_hook(mlx->win, 6, 0, mouse_mov, mlx);
	mlx_key_hook(mlx->win, key_func, mlx);
	mlx_loop_hook(mlx->mlx, loop_hook, mlx);
}

int			loop_hook(t_mlx *mlx)
{
	if (KEYCODE == 69)
		de_zoom(mlx, 1, 1.02);
	if (KEYCODE == 78)
		de_zoom(mlx, -1, 1.02);
	return (0);
}

int			mouse_hook(int button, int x, int y, t_mlx *mlx)
{
	BUTTON = button;
	if (button == 4 && x >= 0 && x < W_WIDTH && y >= 0 && y < W_HEIGHT)
		de_zoom(mlx, 1, 1.1);
	if (button == 5 && x >= 0 && x < W_WIDTH && y >= 0 && y < W_HEIGHT)
		de_zoom(mlx, -1, 1.1);
	return (0);
}

int			mouse_mov(int x, int y, t_mlx *mlx)
{
	X = x;
	Y = y;
	if (mlx->env->mouse_stopped == 0)
	{
		mlx->env->mouse_x = X;
		mlx->env->mouse_y = Y;
		if (FRAC == 1)
			redraw_fractal(mlx);
	}
	return (0);
}

int			key_func(int keycode, t_mlx *mlx)
{
	KEYCODE = keycode;
	if (KEYCODE == 53)
		mlx_free(mlx);
	if (KEYCODE == 49)
		I_MAX += 15;
	if (KEYCODE == 35)
		mlx->env->mouse_stopped = (mlx->env->mouse_stopped == 1) ? 0 : 1;
	if (KEYCODE == 124)
		mlx->env->offset_x += OFFSETX_DELTA / mlx->env->zoom_x / 0.5;
	if (KEYCODE == 123)
		mlx->env->offset_x -= OFFSETX_DELTA / mlx->env->zoom_x / 0.5;
	if (KEYCODE == 126)
		mlx->env->offset_y -= OFFSETY_DELTA / mlx->env->zoom_y / 0.5;
	if (KEYCODE == 125)
		mlx->env->offset_y += OFFSETY_DELTA / mlx->env->zoom_y / 0.5;
	if (KEYCODE == 18)
		FRAC = 0;
	if (KEYCODE == 19 || KEYCODE == 20)
		FRAC = (KEYCODE == 19) ? 1 : 2;
	if (KEYCODE == 18 || KEYCODE == 19 || KEYCODE == 20 || KEYCODE == 15)
		init_frac_values(mlx);
	if (KEYCODE == 36)
		(mlx->env->col_n == 6) ? mlx->env->col_n = 1 : mlx->env->col_n++;
	redraw_fractal(mlx);
	return (0);
}

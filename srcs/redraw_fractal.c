/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <atyrode@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 16:11:00 by atyrode           #+#    #+#             */
/*   Updated: 2017/10/06 16:11:07 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

#ifdef GPU

void			redraw_fractal(t_mlx *mlx)
{
	if (FRAC == 2)
		mlx->env->col_n = 5;
	else if (mlx->env->col_n == 5)
		mlx->env->col_n = 6;
	draw_gpu_fractal(mlx, *mlx->env);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image->image, 0, 0);
	mlx_do_sync(mlx->mlx);
}

#else

void			redraw_fractal(t_mlx *mlx)
{
	if (FRAC == 2)
		mlx->env->col_n = 5;
	else if (mlx->env->col_n == 5)
		mlx->env->col_n = 6;
	fractals(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image->image, 0, 0);
	mlx_do_sync(mlx->mlx);
}

#endif

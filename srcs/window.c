/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <atyrode@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 19:23:07 by atyrode           #+#    #+#             */
/*   Updated: 2017/10/05 15:30:42 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

t_mlx		*mlx_free(t_mlx *mlx)
{
	if (mlx->win != NULL)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->image != NULL)
		delete_image(mlx);
	if (mlx->mandelbrot != NULL)
		ft_memdel((void **)&mlx->mandelbrot);
	if (mlx->cl != NULL)
		ft_memdel((void **)&mlx->cl);
	if (mlx->env != NULL)
		ft_memdel((void **)&mlx->env);
	ft_memdel((void **)&mlx);
	exit(-1);
}

t_mlx		*initialize(void)
{
	t_mlx	*mlx;

	if ((mlx = ft_memalloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	if ((mlx->mlx = mlx_init()) == NULL
		|| (mlx->win = mlx_new_window(mlx->mlx, W_WIDTH, W_HEIGHT,
			"Fract'Ol")) == NULL
		|| (mlx->image = new_image(mlx)) == NULL
		|| (mlx->mandelbrot = ft_memalloc(sizeof(t_mandel))) == NULL
		|| (mlx->cl = ft_memalloc(sizeof(t_cl))) == NULL
		|| (mlx->env = ft_memalloc(sizeof(t_env))) == NULL)
		return (mlx_free(mlx));
	ZOOM = 0;
	return (mlx);
}

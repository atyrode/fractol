/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:41:51 by atyrode           #+#    #+#             */
/*   Updated: 2017/10/03 22:25:28 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

void	set_zoom_center(t_mlx *mlx, int x, int y)
{
	mlx->env->offset_x += OFFSETX_SHRINK((mlx->env->center_x - x) / mlx->env->zoom_x);
	mlx->env->offset_y += OFFSETY_SHRINK((mlx->env->center_y - y) / mlx->env->zoom_y);
	mlx->env->center_x = x;
	mlx->env->center_y = y;
}

int			ft_search(char *str, char *charset)
{
	int		i;

	i = 0;
	if (ft_strlen(str) != 1)
		return (0);
	while (charset[i] != '\0')
	{
		if (charset[i] == str[0])
			return (1);
		i++;
	}
	return (0);
}

int			mouse_hook(int button, int x, int y, t_mlx *mlx)
{
	BUTTON = button;
	if (mlx && x && y)
	//	printf ("button = %d\n", BUTTON);
	/*if (BUTTON == 1 || BUTTON == 2)
	{
		ZOOM = 1.59;
		I_MAX += 20;
		//printf ("ZOOM = %f | X = %d | Y = %d\n", ZOOM, x, y);
		mlx_clear_window(mlx->mlx, mlx->win);
		delete_image(mlx);
		new_image(mlx);
		re_calc_mandel(mlx, x, y);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image->image, 0, 0);
	}*/
	if (button == 4 && x >= 0 && x < W_WIDTH && y >= 0 && y < W_HEIGHT)
	{
		mlx->env->show_center = 0;
		set_zoom_center(mlx, x, y);
		mlx->env->zoom_x *= 1.1;
		mlx->env->zoom_y *= 1.1;
		mlx->mandelbrot->i_max_temp++;
		if (mlx->mandelbrot->i_max_temp > 5)
		{
			mlx->mandelbrot->i_max += 1;
			mlx->mandelbrot->i_max_temp = 0;
		}
		redraw_fractal(mlx);
		set_zoom_center(mlx, W_WIDTH / 2, W_HEIGHT / 2);
	}
	if (button == 5 && x >= 0 && x < W_WIDTH && y >= 0 && y < W_HEIGHT)
	{
		mlx->env->show_center = 0;
		set_zoom_center(mlx, x, y);
		mlx->env->zoom_x /= 1.1;
		mlx->env->zoom_y /= 1.1;
		if (mlx->mandelbrot->i_max_temp > 5)
		{
			mlx->mandelbrot->i_max -= 1;
			mlx->mandelbrot->i_max_temp = 0;
		}
		redraw_fractal(mlx);
		set_zoom_center(mlx, W_WIDTH / 2, W_HEIGHT / 2);
	}
	return (0);
}

int			mouse_mov(int x, int y, t_mlx *mlx)
{
	mlx->env->mouse_x = x;
	mlx->env->mouse_y = y;
	//printf("mouse_x = %d | mouse_y = %d\n", mlx->env->mouse_x, mlx->env->mouse_y);
	redraw_fractal(mlx);
	return (0);
}

int			key_func(int keycode, t_mlx *mlx)
{
	KEYCODE = keycode;
	if (mlx)
		printf("keycode = %d\n", keycode);
	if (KEYCODE == 53)
		mlx_free(mlx);
	if (KEYCODE == 49)
		I_MAX += 15;
	if (FRAC == 1 && (KEYCODE == 126 || KEYCODE == 125))
	{
		if (KEYCODE == 126)
			C_X += 0.005;
		else
			C_Y += 0.01;
	}
	mlx_clear_window(mlx->mlx, mlx->win);
	delete_image(mlx);
	new_image(mlx);
	calc_mandel(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image->image, 0, 0);
	return (0);
}

int			main(int argc, char **argv)
{
	char	*charset;
	t_mlx	*mlx;

	charset = "MJ";
	if (argc != 2 || ft_search(argv[1], charset) == 0)
	{
		ft_putstr("Usage : ./fractol [fractal]\n[M]:Mandelbrot | [J]:Julia |");
		return (0);
	}
	if ((mlx = initialize()) == NULL)
		return (-1);
	if ((ft_strcmp(argv[1], "J")) == 0)
	{
		FRAC = 1;
		X1 = -2.1;
		X2 = 0.6;
		Y1 = -1.2;
		Y2 = 1.2;
		mlx->env->zoom_x = 1;
		mlx->env->zoom_y = 1;
		mlx->env->center_x = W_WIDTH / 2;
		mlx->env->center_y = W_HEIGHT / 2;
		mlx->env->offset_x = OFFSETX_SHRINK(-W_WIDTH / 2);
		mlx->env->offset_y = OFFSETY_SHRINK(W_HEIGHT / 2);
	}
	if ((ft_strcmp(argv[1], "M")) == 0)
	{
		FRAC = 0;
		I_MAX = 100;
		X1 = -2.1;
		X2 = 0.6;
		Y1 = -1.2;
		Y2 = 1.2;
		mlx->env->zoom_x = 1;
		mlx->env->zoom_y = 1;
		mlx->env->center_x = W_WIDTH / 2;
		mlx->env->center_y = W_HEIGHT / 2;
		mlx->env->offset_x = OFFSETX_SHRINK(-W_WIDTH / 2);
		mlx->env->offset_y = OFFSETY_SHRINK(W_HEIGHT / 2);
	}
	opencl_init(mlx);
	//print_mandelbrot(mlx);
	draw_gpu_fractal(mlx, *mlx->env);
	mlx_mouse_hook(mlx->win, mouse_hook, mlx);
	mlx_hook(mlx->win, 6, 0, mouse_mov, mlx);
	/*mlx_key_hook(mlx->win, key_func, mlx);*/
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image->image, 0, 0);
	mlx_loop(mlx->mlx);
	return (0);
}

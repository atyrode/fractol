/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:41:51 by atyrode           #+#    #+#             */
/*   Updated: 2017/10/01 23:53:37 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

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
	if (mlx && x && y)
		printf ("button = %d\n", button);
	if (button == 1)
	{
		ZOOM = 1.59;
		I_MAX += 20;
		printf ("ZOOM = %f | X = %d | Y = %d\n", ZOOM, x, y);
		mlx_clear_window(mlx->mlx, mlx->win);
		delete_image(mlx);
		new_image(mlx);
		re_calc_mandel(mlx, x, y);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image->image, 0, 0);
	}
	return (0);
}

int			mouse_mov(int x, int y, t_mlx *mlx)
{
	if (FRAC == 1)
	{
		printf ("x = %d | y = %d | ZOOM = %f | X1 = %f | X2 = %f\n", x, y, ZOOM, X1, X2);
		C_X = x / ZOOM + X1;
		C_Y = y / ZOOM + X2;
		printf ("C_X = %f | C_Y = %f\n", C_X, C_Y);
	mlx_clear_window(mlx->mlx, mlx->win);
	delete_image(mlx);
	new_image(mlx);
	calc_mandel(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image->image, 0, 0);

	}
	return (0);
}

int			key_func(int keycode, t_mlx *mlx)
{
	if (mlx)
		printf("keycode = %d\n", keycode);
	if (keycode == 53)
		mlx_free(mlx);
	if (keycode == 49)
		I_MAX += 15;
	if (keycode == 6)
		ZOOM += 15;
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

	if ((mlx = initialize()) == NULL)
		return (-1);
	charset = "MJ";
	if (argc != 2 || ft_search(argv[1], charset) == 0)
	{
		ft_putstr("Usage : ./fractol [fractal]\n[M]:Mandelbrot | [J]:Julia |");
		return (0);
	}
	if ((ft_strcmp(argv[1], "J")) == 0)
	{
		FRAC = 1;
		C_X = 0.285;
		C_Y = 0.01;
	}
	if ((ft_strcmp(argv[1], "M")) == 0)
		FRAC = 0;
	print_mandelbrot(mlx);
	mlx_mouse_hook(mlx->win, mouse_hook, mlx);
	mlx_hook(mlx->win, 6, 0, mouse_mov, mlx);
	mlx_key_hook(mlx->win, key_func, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image->image, 0, 0);
	mlx_loop(mlx->mlx);
	return (0);
}

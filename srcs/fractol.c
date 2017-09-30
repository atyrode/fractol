/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:41:51 by atyrode           #+#    #+#             */
/*   Updated: 2017/10/01 00:36:15 by atyrode          ###   ########.fr       */
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
	if (button == 4 || button == 5)
	{
		ZOOM = (button == 4) ? ZOOM * 2 : ZOOM / 2;
		X1 = (button == 4) ? X1 + 0.5 : X1 - 0.5;
		Y2 = (button == 4) ? Y2 - 0.5 : Y2 + 0.5;
		I_MAX = (button == 4) ? I_MAX * 2 : I_MAX / 2;
	}
	//printf ("ZOOM = %d | X = %d | Y = %d\n", ZOOM, x, y);
	mlx_clear_window(mlx->mlx, mlx->win);
	delete_image(mlx);
	new_image(mlx);
	calc_mandel(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image->image, 0, 0);
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
	if (keycode == 126 || keycode == 125)
		SHIFT_Y = (keycode == 125) ? SHIFT_Y + 5 : SHIFT_Y - 5;
	if (keycode == 124 || keycode == 123)
		SHIFT_X = (keycode == 124) ? SHIFT_X + 5 : SHIFT_X - 5;
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
		print_julia(mlx);
	if ((ft_strcmp(argv[1], "M")) == 0)
		print_mandelbrot(mlx);
	mlx_mouse_hook(mlx->win, mouse_hook, mlx);
	mlx_key_hook(mlx->win, key_func, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image->image, 0, 0);
	mlx_loop(mlx->mlx);
	return (0);
}

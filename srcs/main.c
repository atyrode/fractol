/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <atyrode@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 15:27:19 by atyrode           #+#    #+#             */
/*   Updated: 2017/10/05 15:50:28 by atyrode          ###   ########.fr       */
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

int			main(int argc, char **argv)
{
	char	*charset;
	t_mlx	*mlx;

	charset = "MJN";
	if (argc != 2 || ft_search(argv[1], charset) == 0)
	{
		ft_putstr("Usage : ./fractol [fractal]\n[M]:Mandelbrot | [J]:Julia |");
		return (0);
	}
	if ((mlx = initialize()) == NULL)
		return (-1);
	if ((ft_strcmp(argv[1], "J")) == 0)
		FRAC = 1;
	if ((ft_strcmp(argv[1], "M")) == 0)
		FRAC = 0;
	if ((ft_strcmp(argv[1], "N")) == 0)
		FRAC = 2;
	init_frac_values(mlx);
	opencl_init(mlx);
	mlx->init = 0;
	draw_gpu_fractal(mlx, *mlx->env);
	hooks(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image->image, 0, 0);
	mlx_loop(mlx->mlx);
	return (0);
}

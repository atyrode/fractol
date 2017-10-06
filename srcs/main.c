/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <atyrode@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 15:27:19 by atyrode           #+#    #+#             */
/*   Updated: 2017/10/06 14:19:33 by atyrode          ###   ########.fr       */
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

t_mlx		*init_mlx_f(char **argv, int argc)
{
	char	*charset;
	t_mlx	*mlx;

	charset = "MJN";
	if (argc != 2 || ft_search(argv[1], charset) == 0)
	{
		ft_putstr("Usage : ./fractol [fractal]\n[M]:Mandelbrot | [J]:Julia | [N]:Newton\n");
		return (0);
	}
	if ((mlx = initialize()) == NULL)
		return (NULL);
	if ((ft_strcmp(argv[1], "J")) == 0)
		FRAC = 1;
	if ((ft_strcmp(argv[1], "M")) == 0)
		FRAC = 0;
	if ((ft_strcmp(argv[1], "N")) == 0)
		FRAC = 2;
	return (mlx);
}

int			main(int argc, char **argv)
{
	t_mlx	*mlx;

	if ((mlx = init_mlx_f(argv, argc)) == NULL)
		return (-1);
	init_frac_values(mlx);
	# ifdef GPU
	opencl_init(mlx);
	mlx->init = 0;
	draw_gpu_fractal(mlx, *mlx->env);
	#else
	fractals(mlx);
	#endif
	mlx->init = 1;
	hooks(mlx);
	//this effectively put a pixel
	*(int *)mlx->image->ptr = 0xFFFFFF;
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image->image, 0, 0);
	printf ("entering mlx_loop\n");
	mlx_loop(mlx->mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:41:51 by atyrode           #+#    #+#             */
/*   Updated: 2017/09/30 18:46:17 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

int			ft_search(char *str, char *charset)
{
	int		i;
	
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
	
	charset = "MJ";
	if (argc != 2 || ft_search(argv[1], charset) == 0)
	{
		ft_putstr("Usage : ./fractol [fractal]\n[M]:Mandelbrot | [J]:Julia |");
		return (0);
	}
	if (!(ft_strcmp(argv[1], "J")))
		print_julia();
	if (!(ft_strcmp(argv[1], "M")))
		print_mandelbrot();
	ft_putstr("Error\n");
	return (0);
}

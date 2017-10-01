/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:42:07 by atyrode           #+#    #+#             */
/*   Updated: 2017/10/01 22:39:04 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

void		test_func(int id, int ext, t_mlx *mlx)
{
	if (id == 1)
		printf ("X1 = %f | X2 = %f | Y1 = %f | Y2 = %f | ZOOM = %f | I_MAX = %d\n", X1, X2, Y1, Y2, ZOOM, I_MAX);
	if (ext == 1)
		exit(0);
	return ;
}

int			get_rvb(int red, int green, int blue)
{
	int r;
	int g;
	int b;

	r = red & 0xFF;
	g = green & 0xFF;
	b = blue & 0xFF;
	return (r << 16 | g << 8 | b);
}

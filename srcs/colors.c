/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 21:26:32 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/19 21:35:48 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FROM_KERNEL
#include "./../includes/fractol.h"
#endif

int			get_rvb2(int red, int green, int blue)
{
	int r;
	int g;
	int b;

	r = red & 0xFF;
	g = green & 0xFF;
	b = blue & 0xFF;
	return (r << 16 | g << 8 | b);
}

int		color1(t_iter ret, int i_max)
{
	if (ret.i == i_max)
		return (0xFFFFFF);
	else
	//printf("color!\n");
		return ((RGB(
						127.5 * (cos((double)ret.i) + 1),
						127.5 * (sin((double)ret.i) + 1),
						127.5 * (1 - cos((double)ret.i)))));
}

int		color2(t_iter ret, int i_max)
{
	float pct;

	pct = (float)ret.i / (float)i_max;
	if (pct == 1.0)
		return (0xFFFFFF);
	return ((RGB(100, pct * 255, 100)));
}

/*int		color3(t_iter ret, int itermax)
{
	int r;
	int g;
	int b;

	(void)itermax;
	r = 100;
	g = (int)(ret.z * 255.0 / 4.0);
	b = 100;
	return (RGB(r, g, b));
}

int		color4(t_iter ret, int itermax)
{
	float pct;

	pct = (float)ret.i / (float)itermax;
	if (pct == 1.0)
	{
		ret.z = 4.0 - ret.z;
		return (RGB(255, 255, ret.z * 255.0 / 4.0));
	}
	pct *= 0.7;
	pct += 0.30;
	if (pct > 1.0)
		pct = 1.0;
	return (RGB(pct * 255.0, 2, 31));
}

int		color5(t_iter ret, int itermax)
{
	int r;
	int g;
	int b;

	(void)itermax;
	r = (ret.color < 64) ? 255 : 0;
	g = (ret.color < 128 && ret.color > 64) ? 255 : 0;
	b = (ret.color > 128) ? 255 : 0;
	return (RGB(r, g, b));
}*/

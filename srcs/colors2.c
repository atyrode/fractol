/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <atyrode@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 16:00:17 by atyrode           #+#    #+#             */
/*   Updated: 2017/10/06 16:36:29 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

double		clamp_to_pct4(double input, double min, double max)
{
	if (input < min)
		input = min;
	else if (input > max)
		input = max;
	input -= min;
	input = input / (max - min);
	input *= 4.;
	return (input);
}

int			get_color_indicator(double dcr, double dci, int i)
{
	if (dcr > 0.0)
		return (i % 64);
	else if ((dcr < -0.3) && (dci > 0.0))
		return ((i % 64) + 64);
	else
		return ((i % 64) + 128);
}

static int	palette(float pct1, int *p1, int *p2, int *p3)
{
	float		pct2;

	if (pct1 <= 0.5)
	{
		pct1 = pct1 * 2.;
		pct2 = 1.0 - pct1;
		return (RGB(
					(int)(pct2 * p1[0]) + (int)(pct1 * p2[0]),
					(int)(pct2 * p1[1]) + (int)(pct1 * p2[1]),
					(int)(pct2 * p1[2]) + (int)(pct1 * p2[2])));
	}
	else
	{
		pct2 = 1.0 - pct1;
		return (RGB(
					(int)(pct2 * p2[0]) + (int)(pct1 * p3[0]),
					(int)(pct2 * p2[1]) + (int)(pct1 * p3[1]),
					(int)(pct2 * p2[2]) + (int)(pct1 * p3[2])));
	}
}

int			init_palette(float pct1)
{
	int			p1[3];
	int			p2[3];
	int			p3[3];
	int			color;

	p1[0] = 50;
	p1[1] = 0;
	p1[2] = 128;
	p2[0] = 255;
	p2[1] = 14;
	p2[2] = 117;
	p3[0] = 255;
	p3[1] = 255;
	p3[2] = 0;
	color = palette(pct1, p1, p2, p3);
	return (color);
}

int			color6_2(t_iter ret)
{
	double pct;

	pct = ret.z / 4.;
	pct = 1 - pct;
	return (init_palette((float)pct));
}

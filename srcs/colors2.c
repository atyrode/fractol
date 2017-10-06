#include "./../includes/fractol.h"

double   clamp_to_pct4(double input, double min, double max)
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

int      get_color_indicator(double dcr, double dci, int i)
{
	if (dcr > 0.0)
		return (i % 64);
	else if ((dcr < -0.3) && (dci > 0.0))
		return ((i % 64) + 64);
	else
		return ((i % 64) + 128);
}

static int	palette(float pct1)
{
	int	p1[] = {50, 0, 128};
	int	p2[] = {255, 14, 117};
	int	p3[] = {255, 255, 0};
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

int			color6_2(t_iter ret)
{
	double pct;

	pct = ret.z / 4.;
	pct = 1 - pct;
	return (palette((float)pct));
}

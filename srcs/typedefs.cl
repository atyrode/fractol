#define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))
#define X1 -2.1
#define Y1 -1.2

typedef struct	s_iter
{
	int		i;
	double	z;
	int		color;
}				t_iter;

typedef struct	s_calc
{
	double	zoom_x;
	double	zoom_y;
	double	c_x;
	double	c_y;
	double	z_x;
	double	z_y;
	double	tmp;
}				t_calc;

int		color1(t_iter ret, int i_max);
int		color2(t_iter ret, int i_max);
int		color3(t_iter ret, int i_max);
int		color4(t_iter ret, int i_max);
int		color5(t_iter ret, int i_max);
int		color6(t_iter ret, int i_max);

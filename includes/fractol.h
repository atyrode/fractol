/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <atyrode@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:45:22 by atyrode           #+#    #+#             */
/*   Updated: 2017/10/05 14:36:21 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
# define FRACTOL_H

#include "./../libft/includes/libft.h"
#include "./../minilibx_macos/mlx.h"
#include <stdio.h>
# include <math.h>
# include <fcntl.h>
#include <string.h>

#  include <OpenCL/opencl.h>
#  define GPU_SOURCE "srcs/mx.cl"
// #define GPU_SOURCE "mx.cl"
#  define IS_GPU 1

# include "./../srcs/size.h"

# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))
# define OFFSETX_SHRINK(x) (double)(-1 * ((double)(x) / W_WIDTH) * (X2 - X1))
# define OFFSETY_SHRINK(y) (double)(     ((double)(y) / W_HEIGHT) * (Y2 - Y1))
# define OFFSETX_DELTA		OFFSETX_SHRINK(10)
# define OFFSETY_DELTA		OFFSETY_SHRINK(10)
#define W_WIDTH 896
#define W_HEIGHT 800
#define X1 mlx->mandelbrot->x1
#define X2 mlx->mandelbrot->x2
#define Y1 mlx->mandelbrot->y1
#define Y2 mlx->mandelbrot->y2
#define I_MAX mlx->mandelbrot->i_max
#define C_X mlx->mandelbrot->c_x
#define C_Y mlx->mandelbrot->c_y
#define Z_Y mlx->mandelbrot->z_y
#define Z_X mlx->mandelbrot->z_x
#define BPP mlx->image->bpp
#define COORD_X mlx->mandelbrot->coord_x
#define COORD_Y mlx->mandelbrot->coord_y
#define COLOR mlx->mandelbrot->color
#define ZOOM mlx->mandelbrot->zoom
#define FRAC mlx->frac
#define H mlx->mandelbrot->h
#define SQZ_Y mlx->mandelbrot->sqz_y
#define SQZ_X mlx->mandelbrot->sqz_x
#define Z_DZ mlx->mandelbrot->z_dz
#define BUTTON mlx->button
#define KEYCODE mlx->keycode
#define X mlx->env->x
#define Y mlx->env->y
#define OFFSETX mlx->env->offset_x
#define OFFSETY mlx->env->offset_y

typedef struct			s_iter
{
	int		i;
	double	z;
	int		color;
}						t_iter;

typedef struct			s_calc
{
	double	c_x;
	double	c_y;
	double	z_x;
	double	z_y;
	double	tmp;
}						t_calc;

typedef struct			s_mandel {

	double		x1;
	double		y1;
	double		x2;
	double		y2;
	int			i_max_temp;
	int			i_max;
	double		zoom;
	double		c_x;
	double		c_y;
	double		z_y;
	double		sqz_y;
	double		z_x;
	double		sqz_x;
	int			coord_x;
	int			coord_y;
	int			color;

}						t_mandel;

typedef struct			s_image {

	void		*image;
	char		*ptr;
	int			bpp;
	int			stride;
	int			endian;

}						t_image;

typedef struct			s_cl
{
	int					err;
	cl_device_id		device_id;
	cl_context			context;
	cl_command_queue	commands;
	cl_program			program;
	cl_kernel			kernel;
	cl_mem				output;
	size_t				local;
	size_t				global;
}						t_cl;

typedef struct			s_env
{
	//t_iter	(*fractalft)(int, int, struct s_env);
	//int		(*colorft)(t_iter, int);
	char	colorft_num;
	//char	keys[KEYCODE_MAX];
	double	offset_x;
	double	offset_y;
	int		center_x;
	int		center_y;
	char	show_center;
	double	d_zoom_x;
	double	d_zoom_y;
	double	zoom_x;
	double	zoom_y;
	int		mouse_x;
	int		mouse_y;
	int		mouse_changed;
	int		mouse_stopped;
	int		x;
	int		y;
	int		col_n;
}						t_env;

typedef struct			s_mlx {

	int			*mlx;
	int			*win;
	int			frac;
	int			button;
	int			keycode;
	int			init;
	t_image		*image;
	t_mandel	*mandelbrot;
	t_cl		*cl;
	t_env		*env;

}						t_mlx;

void		print_julia(t_mlx *mlx);
void		print_mandelbrot(t_mlx *mlx);
t_mlx		*initialize(void);
void		*new_image(t_mlx *mlx);
void		*delete_image(t_mlx *mlx);
void		image_set_pixel(t_mlx *mlx);
int			get_rvb(int red, int green, int blue);
int			get_rvb2(int red, int green, int blue);
void		calc_mandel(t_mlx *mlx);
void		calc_julia(t_mlx *mlx);
t_mlx		*mlx_free(t_mlx *mlx);
void		re_calc_mandel(t_mlx *mlx, int x, int y);
void		test_func(int id, int exit, t_mlx *mlx);
void		opencl_init(t_mlx *mlx);
char		*load_gpu_sources(void);
void		draw_gpu_fractal(t_mlx *mlx, t_env env);
int			color1(t_iter ret, int i_max);
int			color2(t_iter ret, int i_max);
int			color3(t_iter ret, int i_max);
int			color4(t_iter ret, int i_max);
int			color5(t_iter ret, int i_max);
void		redraw_fractal(t_mlx *mlx);
int 		loop_hook(t_mlx *mlx);
int			mouse_hook(int button, int x, int y, t_mlx *mlx);
int			mouse_mov(int x, int y, t_mlx *mlx);
int			key_func(int keycode, t_mlx *mlx);
void		init_frac_values(t_mlx *mlx);
void		hooks(t_mlx *mlx);
void		reset(t_mlx *mlx);
void		set_zoom_center(t_mlx *mlx, int x, int y);
void		de_zoom(t_mlx *mlx, int i, double j);

#endif

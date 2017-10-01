/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:45:22 by atyrode           #+#    #+#             */
/*   Updated: 2017/10/01 23:16:20 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
# define FRACTOL_H

#include "./../libft/includes/libft.h"
#include "./../minilibx_macos/mlx.h"
#include "./../OpenCL/common/inc/CL/opencl.h"
#include <stdio.h>

#define W_WIDTH 800
#define W_HEIGHT 720
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

typedef struct			s_mandel {

	double		x1;
	double		y1;
	double		x2;
	double		y2;
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

typedef struct			s_mlx {

	int			*mlx;
	int			*win;
	int			frac;
	t_image		*image;
	t_mandel	*mandelbrot;

}						t_mlx;

void		print_julia(t_mlx *mlx);
void		print_mandelbrot(t_mlx *mlx);
t_mlx		*initialize(void);
void		*new_image(t_mlx *mlx);
void		*delete_image(t_mlx *mlx);
void		image_set_pixel(t_mlx *mlx);
int			mouse_hook(int button, int x, int y, t_mlx *mlx);
int			get_rvb(int red, int green, int blue);
void		calc_mandel(t_mlx *mlx);
void		calc_julia(t_mlx *mlx);
t_mlx		*mlx_free(t_mlx *mlx);
void		re_calc_mandel(t_mlx *mlx, int x, int y);
void		test_func(int id, int exit, t_mlx *mlx);

#endif

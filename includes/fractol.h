/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:45:22 by atyrode           #+#    #+#             */
/*   Updated: 2017/10/01 00:36:11 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
# define FRACTOL_H

#include "./../libft/includes/libft.h"
#include "./../minilibx_macos/mlx.h"
#include <stdio.h>

#define W_WIDTH 800
#define W_HEIGHT 720
#define X1 mlx->mandelbrot->x1
#define X2 mlx->mandelbrot->x2
#define Y1 mlx->mandelbrot->y1
#define Y2 mlx->mandelbrot->y2
#define IMAGE_X mlx->mandelbrot->image_x
#define IMAGE_Y mlx->mandelbrot->image_y
#define I_MAX mlx->mandelbrot->i_max
#define ZOOM_X mlx->mandelbrot->zoom_x
#define ZOOM_Y mlx->mandelbrot->zoom_y
#define C_R mlx->mandelbrot->c_r
#define C_I mlx->mandelbrot->c_i
#define Z_R mlx->mandelbrot->z_r
#define Z_I mlx->mandelbrot->z_i
#define BPP mlx->image->bpp
#define COORD_X mlx->mandelbrot->coord_x
#define COORD_Y mlx->mandelbrot->coord_y
#define COLOR mlx->mandelbrot->color
#define ZOOM mlx->mandelbrot->zoom
#define SHIFT_X mlx->mandelbrot->shift_x
#define SHIFT_Y mlx->mandelbrot->shift_y

typedef struct			s_mandel {

	double		x1;
	double		y1;
	double		x2;
	double		y2;
	double		image_x;
	double		image_y;
	int			i_max;
	double		zoom_x;
	double		zoom_y;
	double		zoom;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	int			coord_x;
	int			shift_x;
	int			coord_y;
	int			shift_y;
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
t_mlx		*mlx_free(t_mlx *mlx);

#endif

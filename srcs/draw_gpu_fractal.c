/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gpu_fractal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 21:08:11 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/19 22:31:03 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

static void	throw_kernel(char *errmsg)
{
	dprintf(2, "OpenCL: %s\n", errmsg);
	exit(1);
}

static void	set_kernel_args(t_env *env, t_cl *cl, t_mandel *mandelbrot, t_mlx *mlx)
{
	int		err;

	err = clSetKernelArg(cl->kernel, 0, sizeof(cl_mem), &cl->output);
	err |= clSetKernelArg(cl->kernel, 1, sizeof(int), &mlx->frac);
	err |= clSetKernelArg(cl->kernel, 2, sizeof(double), &mandelbrot->x1);
	err |= clSetKernelArg(cl->kernel, 3, sizeof(double), &mandelbrot->y1);
	err |= clSetKernelArg(cl->kernel, 4, sizeof(int), &mandelbrot->i_max);
	err |= clSetKernelArg(cl->kernel, 5, sizeof(double), &env->d_zoom_x);
	err |= clSetKernelArg(cl->kernel, 6, sizeof(double), &env->d_zoom_y);
	err |= clSetKernelArg(cl->kernel, 7, sizeof(int), &env->center_x);
	err |= clSetKernelArg(cl->kernel, 8, sizeof(int), &env->center_y);
	err |= clSetKernelArg(cl->kernel, 9, sizeof(double), &env->offset_x);
	err |= clSetKernelArg(cl->kernel, 10, sizeof(double), &env->offset_y);
	err |= clSetKernelArg(cl->kernel, 11, sizeof(int), &env->mouse_x);
	err |= clSetKernelArg(cl->kernel, 12, sizeof(int), &env->mouse_y);
	if (err != CL_SUCCESS)
		throw_kernel("Failed to set kernel arguments");
}

static void	set_cl_global(t_mlx *mlx)
{
	mlx->cl->global = W_WIDTH * W_HEIGHT;
	if (mlx->cl->global % mlx->cl->local)
	{
		dprintf(2, "Error: OpenCL will crash:\n");
		dprintf(2, "WIN_W * WIN_H must be a multiple of local: %lu\n",
				mlx->cl->local);
		exit(1);
	}
}

void		draw_gpu_fractal(t_mlx *mlx, t_env env)
{
	int		err;

	//printf ("redrawn\n");
	env.d_zoom_x = env.zoom_x * W_WIDTH / (X2 - X1);
	env.d_zoom_y = env.zoom_y * W_HEIGHT / (Y2 - Y1);
	//printf ("d_zoom_x = %f | d_zoom_y = %f | center_x = %d | center_y = %d | offset_x = %f | offset_y = %f | x1 = %f | x2 = %f | y1 = %f | y2 = %f\n",
	//mlx->env->d_zoom_x, mlx->env->d_zoom_y, mlx->env->center_x, mlx->env->center_y, mlx->env->offset_x, mlx->env->offset_y, mlx->mandelbrot->x1, mlx->mandelbrot->x2, mlx->mandelbrot->y1, mlx->mandelbrot->y2);
	set_kernel_args(&env, mlx->cl, mlx->mandelbrot, mlx);
	err = clGetKernelWorkGroupInfo(mlx->cl->kernel, mlx->cl->device_id,
			CL_KERNEL_WORK_GROUP_SIZE, sizeof(mlx->cl->local), &mlx->cl->local, NULL);
	if (err != CL_SUCCESS)
		throw_kernel("Failed to retrieve kernel work group info");
	set_cl_global(mlx);
	err = clEnqueueNDRangeKernel(mlx->cl->commands, mlx->cl->kernel, 1, NULL,
			&mlx->cl->global, &mlx->cl->local, 0, NULL, NULL);
	if (err)
		throw_kernel("Failed to execute kernel !");
	clFinish(mlx->cl->commands);
	err = clEnqueueReadBuffer(mlx->cl->commands, mlx->cl->output, CL_TRUE,
			0, W_WIDTH * W_HEIGHT * 4, mlx->image->ptr, 0, NULL, NULL);
	if (err != CL_SUCCESS)
		throw_kernel("Failed to read output array");
}

void	redraw_fractal(t_mlx *mlx)
{
	draw_gpu_fractal(mlx, *mlx->env);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image->image, 0, 0);
	mlx_do_sync(mlx->mlx);
}

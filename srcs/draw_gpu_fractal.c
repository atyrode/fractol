/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gpu_fractal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <atyrode@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 15:28:33 by atyrode           #+#    #+#             */
/*   Updated: 2017/10/06 18:59:00 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

#ifdef GPU

static void		throw_kernel(char *errmsg)
{
	dprintf(2, "OpenCL: %s\n", errmsg);
	exit(1);
}

static void		k_arg(t_env *env, t_cl *cl, t_mandel *mandelbrot, t_mlx *mlx)
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
	err |= clSetKernelArg(cl->kernel, 13, sizeof(int), &env->col_n);
	if (err != CL_SUCCESS)
		throw_kernel("Failed to set kernel arguments");
}

static void		set_cl_global(t_mlx *mlx)
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

void			draw_gpu_fractal(t_mlx *mlx, t_env env)
{
	int		err;

	env.d_zoom_x = env.zoom_x * W_WIDTH / (X2 - X1);
	env.d_zoom_y = env.zoom_y * W_HEIGHT / (Y2 - Y1);
	k_arg(&env, mlx->cl, mlx->mandelbrot, mlx);
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

#endif

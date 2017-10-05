/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <atyrode@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 15:29:18 by atyrode           #+#    #+#             */
/*   Updated: 2017/10/05 18:01:57 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

# ifdef GPU

static int	try_opencl_init_next(t_cl *cl)
{
	char		buffer[10000];
	size_t		len;

	cl->err = clBuildProgram(cl->program, 0, NULL, "-I./srcs/", NULL, NULL);
	if (cl->err != CL_SUCCESS)
	{
		cl->err = clGetProgramBuildInfo(cl->program, cl->device_id,
				CL_PROGRAM_BUILD_LOG, 10000, buffer, &len);
		if (cl->err == CL_SUCCESS)
			dprintf(2, "Compiler error message :\n%s\n", buffer);
		else
		{
			dprintf(2, "Error while retrieving compiler log\n");
			dprintf(2, "Try increasing buffer size to 100 000\n");
		}
		return (-5);
	}
	cl->kernel = clCreateKernel(cl->program, "iterate", &cl->err);
	if (!cl->kernel || cl->err != CL_SUCCESS)
		return (-6);
	cl->output = clCreateBuffer(cl->context, CL_MEM_WRITE_ONLY,
			W_HEIGHT * W_WIDTH * 4, NULL, NULL);
	if (!cl->output)
		return (-7);
	return (0);
}

static int	try_opencl_init(t_mlx *mlx)
{
	static char	*kernel_source;
	t_cl		*cl;

	cl = mlx->cl;
	cl->err = clGetDeviceIDs(NULL, CL_DEVICE_TYPE_GPU, 1, &cl->device_id, NULL);
	if (cl->err != CL_SUCCESS)
		return (-1);
	cl->context = clCreateContext(0, 1, &cl->device_id, NULL, NULL, &cl->err);
	if (!cl->context)
		return (-2);
	cl->commands = clCreateCommandQueue(cl->context, cl->device_id, 0,
			&cl->err);
	if (!cl->commands)
		return (-3);
	kernel_source = load_gpu_sources();
	cl->program = clCreateProgramWithSource(cl->context, 1,
			(const char**)&kernel_source, NULL, &cl->err);
	if (!cl->program)
		return (-4);
	return (try_opencl_init_next(cl));
}

void		opencl_init(t_mlx *e)
{
	int	err;

	err = try_opencl_init(e);
	if (err == 0)
	{
		printf("OpenCL init succeeded\n");
		return ;
	}
	printf("OpenCL init failed (%d)\n", err);
	exit(1);
}

#endif

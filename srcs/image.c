/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <atyrode@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:42:48 by atyrode           #+#    #+#             */
/*   Updated: 2017/10/05 19:55:03 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

void	image_set_pixel(t_mlx *mlx)
{
	if (COORD_X < 0 || COORD_X >= W_WIDTH || COORD_Y < 0 || COORD_Y >= W_HEIGHT)
		return ;
	*(int *)(mlx->image->ptr + ((COORD_X + COORD_Y * W_WIDTH) * BPP)) = COLOR;
}

void	*delete_image(t_mlx *mlx)
{
	if (mlx->image != NULL)
	{
		if (mlx->image->image != NULL)
			mlx_destroy_image(mlx->mlx, mlx->image->image);
		ft_memdel((void **)&mlx->image);
	}
	return (NULL);
}

void	*new_image(t_mlx *mlx)
{
	if ((mlx->image = ft_memalloc(sizeof(t_image))) == NULL)
		return (NULL);
	if ((mlx->image->image = mlx_new_image(mlx->mlx, W_WIDTH, W_HEIGHT))
			== NULL)
		return (delete_image(mlx));
	mlx->image->ptr = mlx_get_data_addr(mlx->image->image, &mlx->image->bpp,
			&mlx->image->stride, &mlx->image->endian);
	mlx->image->bpp /= 8;
	return (mlx->image);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_gpu_sources.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 15:31:24 by atyrode           #+#    #+#             */
/*   Updated: 2017/10/05 15:31:29 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

static char	*load_file(char *ret, int fd)
{
	int		retgnl;
	char	*line;
	char	*ret_old;

	while (1)
	{
		retgnl = get_next_line(fd, &line);
		if (retgnl == 0)
			break ;
		else if (retgnl == -1)
		{
			dprintf(2, "Failed to load GPU source\n");
			exit(1);
		}
		ret_old = ret;
		ret = ft_strjoin3(ret_old, "\n", line);
		free(ret_old);
		free(line);
	}
	close(fd);
	ret_old = ret;
	ret = ft_strjoin(ret_old, "\n");
	free(ret_old);
	return (ret);
}

static char	*try_load_file(char *filename, char *ret)
{
	int fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		dprintf(2, "Failed to open GPU source : %s\n", filename);
		exit(1);
	}
	ret = load_file(ret, fd);
	return (ret);
}

char		*load_gpu_sources(void)
{
	char	*ret;

	ft_check_malloc((ret = ft_strdup("#define FROM_KERNEL\n")));
	ret = try_load_file(GPU_SOURCE, ret);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 20:38:32 by atyrode           #+#    #+#             */
/*   Updated: 2017/09/22 20:45:10 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strfindchr(char *str, char c)
{
	int		i;

	if (c == '\0')
		return (ft_strlen(str));
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		else
			i++;
	}
	return (-1);
}

int		ft_transfer_else(char *src, char **dest, int pos, char *tmp)
{
	int		i;

	i = 0;
	src[pos] = '\0';
	*dest = ft_strjoin(*dest, src);
	free(tmp);
	pos++;
	while (src[pos] != '\0')
	{
		src[i] = src[pos];
		i++;
		pos++;
	}
	src[i] = '\0';
	return (1);
}

int		ft_transfer(char *src, char **dest)
{
	int		pos;
	int		i;
	char	*tmp;

	i = 0;
	pos = ft_strfindchr(src, '\n');
	tmp = *dest;
	if (pos == -1)
	{
		*dest = ft_strjoin(*dest, src);
		free(tmp);
		src[0] = '\0';
		return (0);
	}
	else
		return (ft_transfer_else(src, dest, pos, tmp));
}

int		normidead(char *buffer, int read_ret, char **line, const int fd)
{
	if (ft_transfer(buffer, line))
		return (1);
	while ((read_ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[read_ret] = '\0';
		if (ft_transfer(buffer, line))
			return (1);
	}
	if (read_ret == 0)
		return (ft_strlen(*line) == 0 ? 0 : 1);
	free(*line);
	*line = NULL;
	return (-1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*buffer;
	static int		current_fd = -1;
	int				read_ret;

	read_ret = 0;
	if (fd < 0 || !line)
		return (-1);
	if (!buffer && (buffer = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1)))
			== NULL)
		return (-1);
	if (fd != current_fd)
		buffer[0] = '\0';
	current_fd = fd;
	*line = ft_strnew(0);
	return (normidead(buffer, read_ret, line, fd));
}

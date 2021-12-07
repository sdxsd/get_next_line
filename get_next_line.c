/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmaguire <wmaguire@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/04 15:58:01 by wmaguire      #+#    #+#                 */
/*   Updated: 2021/12/05 18:03:10 by wmaguire      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*merge(char *buf_1, char *buf_2)
{
	char	*merged;

	merged = gnl_strjoin(buf_1, buf_2);
	if (!merged)
		return (NULL);
	return (merged);
}

static ssize_t	read_data(char **buf, int fd)
{
	ssize_t	bytes_read;
	char	*buf_2;
	char	*merged;

	bytes_read = read(fd, *buf, BUFFER_SIZE);
	if (bytes_read > 0 && !is_newline(*buf, BUFFER_SIZE))
	{
		buf_2 = malloc(sizeof(char) * BUFFER_SIZE);
		bytes_read += read_data(&buf_2, fd);
		merged = merge(*buf, buf_2);
		free(*buf);
		free(buf_2);
		*buf = merged;
	}
	return (bytes_read);
}

int	to_newline(char *buf)
{
	int	iterator;

	iterator = 0;
	while (buf[iterator] != '\0' && buf[iterator] != '\n')
		iterator++;
	return (iterator + 1);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	static int	offset;
	ssize_t		bytes_read;
	char		*line;
	char		*tmp;

	if (!buf)
	{
		buf = malloc(sizeof(char) * BUFFER_SIZE);
		bytes_read = read_data(&buf, fd);
		if (bytes_read == 0 && ft_strlen(buf) == 0)
		{
			tmp = buf;
			buf = NULL;
			free(tmp);
			offset = 0;
			return (NULL);
		}
		if (bytes_read < 0)
			return (NULL);
	}
	line = gnl_strndup((buf + offset), to_newline(buf + offset));
	offset += ft_strlen(line);
	if (offset >= (int)ft_strlen(buf))
	{
		tmp = buf;
		buf = NULL;
		free(tmp);
		offset = 0;
	}
	return (line);
}

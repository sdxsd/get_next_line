/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmaguire <wmaguire@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/04 15:58:01 by wmaguire      #+#    #+#                 */
/*   Updated: 2021/11/24 15:18:31 by wmaguire      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

// What Job would suggest:
// Make it read until newline found or until end of file/error

// What if read returns 0 or -1 everything is completely fucked
// nothing works ~ Job
static ssize_t	read_data(char *buf, int fd)
{
	ssize_t	bytes_read;
	ssize_t	read_return;
	char	*buf_2;
	char	*tmp;

	read_return = read(fd, buf, BUFFER_SIZE);
	if (!read_return)
		read_return = ft_strlen(buf);
	else if (read_return < 0)
		return (0);
	bytes_read = read_return;
	while (!is_newline(buf, ft_strlen(buf)))
	{
		buf_2 = malloc(sizeof(char) * BUFFER_SIZE + 1);
		bytes_read += read(fd, buf_2, BUFFER_SIZE + 1);
		tmp = buf;
		buf = gnl_strjoin(buf, buf_2);
		free(tmp);
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

	buf = malloc(sizeof(char) * BUFFER_SIZE);
	bytes_read = read_data(buf, fd);
	line = gnl_strndup((buf + offset), to_newline(buf + offset));
	offset += ft_strlen(line);
	return (line);
}

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
#include <stdio.h>

// Resets offset and frees buf when
// get_next_line reaches end of file, or needs to make a new buf.
static char	*reset(int *offset, char **buf)
{
	*offset = 0;
	free(*buf);
	*buf = NULL;
	return (NULL);
}

// Returns the resulting
// String made by combining the two arguments.
char	*merge(char **buf_1, char **buf_2)
{
	char	*merged;

	merged = gnl_strjoin(*buf_1, *buf_2);
	if (!merged)
		return (NULL);
	free(*buf_1);
	free(*buf_2);
	*buf_1 = merged;
	return (merged);
}

// Returns how many characters until the next newline.
int	to_newline(char *buf)
{
	ssize_t	iterator;

	iterator = 0;
	while (buf[iterator] != '\0' && buf[iterator] != '\n')
		iterator++;
	if (buf[iterator] == '\0')
		return (iterator);
	return (iterator + 1);
}

// Reads data continuously until buffer contains a newline character.
// Reads into, and then merges a temporary buffer with the original buffer
// until a newline is found.
// Returns the amount of bytes read.
static ssize_t	read_data(char **buf, int fd)
{
	ssize_t	bytes_read;
	ssize_t	ret_2;
	char	*buf_2;

	bytes_read = read(fd, *buf, BUFFER_SIZE);
	if (bytes_read > 0 && to_newline(*buf) > 0)
	{
		buf_2 = ft_calloc(sizeof(char), BUFFER_SIZE);
		if (!buf_2)
			return (0);
		ret_2 = read_data(&buf_2, fd);
		if (ret_2 > 0)
		{
			bytes_read += ret_2;
			merge(buf, &buf_2);
		}
	}
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	static int	offset;
	ssize_t		bytes_read;
	char		*line;

	if (!buf)
	{
		buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		bytes_read = read_data(&buf, fd);
		if (bytes_read == 0)
			return (reset(&offset, &buf));
		else if (bytes_read < 0)
			return (NULL);
	}
	line = gnl_strndup((buf + offset), to_newline(buf + offset));
	offset += ft_strlen(line);
	if (offset >= (int)ft_strlen(buf))
		reset(&offset, &buf);
	return (line);
}

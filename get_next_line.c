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
		read_return = ft_strlen((char *)buf);
	else if (read_return == -1)
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

// Make read continue to read if newline is not encountered
static char	*gnl_getline(void *buf, size_t bufsize)
{
	char	*c_buf;
	char	*line;
	size_t	iterator;

	if (!buf)
		return (NULL);
	c_buf = (char *)buf;
	iterator = 0;
	while (c_buf[iterator] != '\n')
	{
		if (iterator >= bufsize)
			break ;
		iterator++;
	}
	line = gnl_strndup(c_buf, iterator + 1);
	return (line);
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
	static char		*buf;
	char			*line;
	ssize_t			bytes_read;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	bytes_read = read_data(buf, fd);
	line = gnl_strndup(buf, to_newline(buf));
	buf += ft_strlen(line);
	return (line);
}


int main(void)
{
	int fd = open("gentoo.txt", O_RDWR);
	printf("%s", get_next_line(fd));
	printf("SECOND CALL: %s", get_next_line(fd));
	//printf("THIRD CALL: %s", get_next_line(fd));
	//printf("FOURTH CALL: %s", get_next_line(fd));
	//printf("FIFTH CALL: %s", get_next_line(fd));
	//printf("SIXTH CALL: %s", get_next_line(fd));
	//printf("SEVENTH CALL: %s", get_next_line(fd));
}

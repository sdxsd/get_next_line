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

	read_return = read(fd, buf, BUFFER_SIZE);
	if (!read_return)
		read_return = ft_strlen((char *)buf);
	else if (read_return == -1)
		return (0);
	bytes_read = read_return;
	while (!is_newline(buf, read_return))
	{
		buf_2 = malloc(sizeof(char) * BUFFER_SIZE + 1);
		bytes_read += read(fd, buf_2, BUFFER_SIZE + 1);
		buf = merge(buf, buf_2);
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

char	*merge(char *cur_rem, char *new_rem)
{
	char	*merged;

	if (!cur_rem)
		cur_rem = gnl_strndup("", 1);
	merged = gnl_strjoin(cur_rem, new_rem);
	free(cur_rem);
	free(new_rem);
	if (!merged)
		return (NULL);
	return (merged);
}

// Make buf a coole kanjer char *
char	*get_next_line(int fd)
{
	static char	*buf;
	ssize_t		bytes_read;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	bytes_read = read_data(buf, fd);
	printf("%s", buf);
	return (buf);
}


int main(void)
{
	int fd = open("gentoo.txt", O_RDWR);
	printf("FIRST CALL: %s", get_next_line(fd));
	//printf("SECOND CALL: %s", get_next_line(fd));
	//printf("THIRD CALL: %s", get_next_line(fd));
	//printf("FOURTH CALL: %s", get_next_line(fd));
	//printf("FIFTH CALL: %s", get_next_line(fd));
	//printf("SIXTH CALL: %s", get_next_line(fd));
	//printf("SEVENTH CALL: %s", get_next_line(fd));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmaguire <wmaguire@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/04 15:58:01 by wmaguire      #+#    #+#                 */
/*   Updated: 2021/11/11 15:18:31 by wmaguire      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static size_t	read_data(void	*buf, int fd)
{
	size_t	bytes_read;

	bytes_read = read(fd, buf, BUFFER_SIZE);
	return (bytes_read);
}

static char	*gnl_getline(void *buf, size_t bufsize)
{
	char	*c_buf;
	char	*line;
	size_t	iterator;

	c_buf = (char *)buf;
	iterator = 0;
	while (c_buf[iterator] != '\n')
	{
		if (iterator >= bufsize)
			break ;
		iterator++;
	}
	line = gnl_strndup(c_buf, iterator);
	return (line);
}

static char	*gnl_remainder(void *buf, size_t remainder_len)
{
	char	*remainder;

	remainder = gnl_strndup((char *)buf, remainder_len);
	return (remainder);
}

static char	*join_remainder(char *cur_rem, char *new_rem)
{
	char	*merged;

	merged = gnl_strjoin(cur_rem, new_rem);
	free(cur_rem);
	free(new_rem);
	if (!merged)
		return (NULL);
	return (merged);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	size_t		bytes_read;
	void		*buf;

	bytes_read = read_data(buf, fd);
	gnl_getline();
}

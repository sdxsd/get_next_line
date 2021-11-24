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

static ssize_t	read_data(void	*buf, int fd)
{
	ssize_t	bytes_read;
	void	*buf_2;

	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (!bytes_read)
		bytes_read = ft_strlen((char *)buf);
	else if (bytes_read == -1)
		return (0);
	while (!is_newline(buf, bytes_read))
	{
		buf_2 = malloc(sizeof(char) * BUFFER_SIZE);
		bytes_read += read(fd, buf_2, BUFFER_SIZE);
		buf = merge((char *)buf, (char *)buf_2);
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

static char	*gnl_remainder(void *buf, size_t remainder_len)
{
	char	*remainder;

	remainder = gnl_strndup((char *)buf, remainder_len);
	return (remainder);
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

// Handle errors with read()
char	*get_next_line(int fd)
{
	static char	*rem;
	ssize_t		bytes_read;
	void		*buf;
	char		*c_buf;
	size_t		lsize;
	char		*rem_ptr;

	if (rem && is_newline(rem, ft_strlen(rem)))
	{
		c_buf = gnl_getline(rem, ft_strlen(rem));
		rem_ptr = rem;
		rem = gnl_strndup(rem + ft_strlen(c_buf), ft_strlen(rem) - ft_strlen(c_buf));
		free(rem_ptr);
		return (c_buf);
	}
	if (fd < 0)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
		return (NULL);
	bytes_read = read_data(buf, fd);
	if (bytes_read == -1)
		return (NULL);
	if (!bytes_read)
		bytes_read = ft_strlen((char *)buf);
	c_buf = gnl_getline(buf, bytes_read);
	free(buf);
	lsize = ft_strlen(c_buf);
	rem = merge(rem, gnl_remainder(buf + lsize, (BUFFER_SIZE - lsize)));
	if (!rem)
		return (NULL);
	return (c_buf);
}


int main(void)
{
	int fd = open("gentoo.txt", O_RDWR);
	printf("FIRST CALL: %s", get_next_line(fd));
	printf("SECOND CALL: %s", get_next_line(fd));
	printf("THIRD CALL: %s", get_next_line(fd));
	printf("FOURTH CALL: %s", get_next_line(fd));
	printf("FIFTH CALL: %s", get_next_line(fd));
	printf("SIXTH CALL: %s", get_next_line(fd));
	printf("SEVENTH CALL: %s", get_next_line(fd));
}

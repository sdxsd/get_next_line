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
#include <stdio.h>
#include <fcntl.h>

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
	line = gnl_strndup(c_buf, iterator + 1);
	return (line);
}

static char	*gnl_remainder(void *buf, size_t remainder_len)
{
	char	*remainder;

	remainder = gnl_strndup((char *)buf, remainder_len);
	return (remainder);
}

static char	*j_rem(char *cur_rem, char *new_rem)
{
	char	*merged;

	if (!cur_rem)
		cur_rem = gnl_strndup("", 2);
	merged = gnl_strjoin(cur_rem, new_rem);
	free(cur_rem);
	free(new_rem);
	if (!merged)
		return (NULL);
	return (merged);
}

char	*get_next_line(int fd)
{
	static char	*rem;
	size_t		bytes_read;
	void		*buf;
	char		*c_buf;
	size_t		lsize;

	buf = malloc(sizeof(char) * BUFFER_SIZE);
	bytes_read = read_data(buf, fd);
	if (!bytes_read)
		bytes_read = ft_strlen((char *)buf);
	c_buf = gnl_getline(buf, bytes_read);
	lsize = ft_strlen(c_buf);
	rem = j_rem(rem, gnl_remainder(buf + lsize, (BUFFER_SIZE - lsize)));
	return (c_buf);
}

/*
int main(void)
{
	int fd = open("gentoo.txt", O_RDWR);
	printf("FIRST CALL: %s", get_next_line(fd));
	printf("SECOND CALL: %s", get_next_line(fd));
	printf("THIRD CALL: %s", get_next_line(fd));
}
*/

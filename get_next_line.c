/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmaguire <wmaguire@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/04 15:58:01 by wmaguire      #+#    #+#                 */
/*   Updated: 2021/11/05 12:05:25 by wmaguire      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

static char	*get_newline(int size, void *buf)
{
	;
}

char	*get_next_line(int fd)
{
	static int	f_mark;
	char		*line;
	void		*buf;
	size_t		read_c;

	if (fd == -1)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE);
	read_c = read(fd, buf, BUFFER_SIZE);
	if (read_c == READ_ERROR)
		return (READ_ERROR);
	if (read_c == EOF)
		get_newline(BUFFER_SIZE, buf);
	return (get_newline(read_c, buf));
}

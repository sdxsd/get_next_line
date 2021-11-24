/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmaguire <wmaguire@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/05 12:27:13 by wmaguire      #+#    #+#                 */
/*   Updated: 2021/11/09 13:57:51 by wmaguire      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*gnl_memcpy(void *dst, const void *src, size_t n)
{
	size_t			iterator;
	const char		*src_ptr;
	char			*dst_ptr;

	if (dst == NULL && src == NULL)
		return (dst);
	iterator = 0;
	src_ptr = src;
	dst_ptr = dst;
	while (iterator < n)
	{
		dst_ptr[iterator] = src_ptr[iterator];
		++iterator;
	}
	return (dst);
}

char	*gnl_strndup(const char *s1, size_t len)
{
	char	*dupe_str;

	dupe_str = malloc((sizeof(char) * len) + 1);
	if (!dupe_str)
		return (NULL);
	gnl_memcpy(dupe_str, s1, len);
	dupe_str[len] = '\0';
	return (dupe_str);
}

size_t	ft_strlen(const char *str)
{
	size_t	iterator;

	iterator = 0;
	while (str[iterator] != '\0')
		++iterator;
	return (iterator);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*b_str;
	int		s1_l;
	int		s2_l;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_l = ft_strlen(s1);
	s2_l = ft_strlen(s2);
	str = malloc((s1_l + s2_l) + 1);
	if (!str)
		return (NULL);
	b_str = str;
	gnl_memcpy(str, (char *)s1, s1_l);
	str += s1_l;
	gnl_memcpy(str, (char *)s2, s2_l);
	str += s2_l;
	*str = '\0';
	return (b_str);
}

int	is_newline(void	*buf, ssize_t bytes_read)
{
	ssize_t	iterator;
	char	*c_buf;

	c_buf = (char *)buf;
	iterator = 0;
	while (iterator < bytes_read)
	{
		if (c_buf[iterator] == '\n')
			return (1);
		iterator++;
	}
	return (0);
}

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

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	iterator;

	iterator = 0;
	while (iterator < n && src[iterator] != '\0')
	{
		dest[iterator] = src[iterator];
		++iterator;
	}
	while (iterator < n)
	{
		dest[iterator] = '\0';
		iterator++;
	}
	return (dest);
}

char	*gnl_strndup(const char *s1, size_t len)
{
	char	*dupe_str;

	dupe_str = malloc((sizeof(char) * len) + 1);
	if (!dupe_str)
		return (NULL);
	ft_strncpy(dupe_str, s1, len);
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
	ft_strncpy(str, (char *)s1, s1_l);
	str += s1_l;
	ft_strncpy(str, (char *)s2, s2_l);
	str += s2_l;
	*str = '\0';
	return (b_str);
}

int	is_newline(char	*buf, ssize_t bytes_read)
{
	ssize_t	iterator;

	iterator = 0;
	while (iterator < bytes_read)
	{
		if (buf[iterator] == '\n')
			return (1);
		iterator++;
	}
	return (0);
}

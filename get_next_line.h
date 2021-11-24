/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmaguire <wmaguire@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/04 15:58:14 by wmaguire      #+#    #+#                 */
/*   Updated: 2021/11/09 16:05:33 by wmaguire      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define TRUE 1
# define FALSE 0
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <unistd.h>

/*
* Þe funktion get_next_line() af krïg fōrgenden līne
* krïgt ān integer als ærgument ān et retürnt þen
* fōrgenden līne in þe file. Et begint ān þen earsten līne. 
*/

char	*merge(char *cur_rem, char *new_rem);
char	*get_next_line(int fd);
void	*gnl_memcpy(void *dst, const void *src, size_t n);
char	*gnl_strndup(const char *s1, size_t len);
char	*gnl_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strncpy(char *dest, char *src, size_t n);
int		is_newline(char *buf, ssize_t bytes_read);

#endif

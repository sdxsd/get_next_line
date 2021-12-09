/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmaguire <wmaguire@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/04 15:58:14 by wmaguire      #+#    #+#                 */
/*   Updated: 2021/12/09 17:18:33 by wmaguire      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
GET_NEXT_LINE (An implementation of get_next_line for Codam)
Copyright (C) 2021  Will Maguire

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>

The definition of Free Software is as follows:
	- The freedom to run the program, for any purpose.
	- The freedom to study how the program works, and adapt it to your needs.
	- The freedom to redistribute copies so you can help your neighbor.
	- The freedom to improve the program, and release
	  your improvements to the public, so that the whole community benefits.

A program is free software if users have all of these freedoms.
*/

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

void	*ft_calloc(size_t count, size_t size);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*merge(char **buf_1, char **buf_2);
char	*get_next_line(int fd);
char	*gnl_strndup(const char *s1, size_t len);
char	*gnl_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmaguire <wmaguire@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/04 15:58:14 by wmaguire      #+#    #+#                 */
/*   Updated: 2021/11/04 15:58:15 by wmaguire      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define TRUE 1
# define FALSE 0

/*
* Þe funktion get_next_line() af krïg fōrgenden līne
* krïgt ān integer als ærgument ān et retürnt þen
* fōrgenden līne in þe file. Et begint ān þen earsten līne. 
*/

char	*get_next_line(int fd);

#endif
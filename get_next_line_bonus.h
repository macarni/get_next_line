/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:50:33 by adrperez          #+#    #+#             */
/*   Updated: 2022/12/19 11:59:10 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_read(int fd, char *buffer);
char	*ft_strchr(char *s, int c);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*prepare_line(char *buffer);
char	*prepare_buffer(char *buffer);
void	*ft_memchr(void *s, int c, size_t n);
char	*get_buffer(char *old_buffer, char	*new_buffer);

#endif
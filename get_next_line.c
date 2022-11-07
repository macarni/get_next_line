/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:49:07 by adrperez          #+#    #+#             */
/*   Updated: 2022/11/04 14:55:23 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *buffer)
{
	int bytes;
	bytes = read(fd, buffer, BUFFER_SIZE);
	return (buffer);
}

char *get_next_line(int fd)
{
	char		*line;
	static char	*buffer;
	
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	line = ft_read(fd, buffer);
	return (buffer);
}
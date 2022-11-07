/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:49:07 by adrperez          #+#    #+#             */
/*   Updated: 2022/11/07 13:50:18 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*concat_lines(char *original, char *new_line)
{
	size_t	len;
	char	*concat;

	write(1, "hola", 4);
	len = ft_strlen(original) + ft_strlen(new_line);
	concat = ft_calloc(len + 1, sizeof(char));
	if (!concat)
		return (NULL);
	concat = ft_strjoin(original, new_line);
	
	return (concat);
		
}

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
	
	line = NULL;
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	while (!line || !ft_strchr(line, '\n'))
	{
		if (!*buffer)
		{
			buffer = ft_read(fd, buffer);	
		}
		line = concat_lines(line, buffer);
	}
	return (line);
}
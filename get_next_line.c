/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:49:07 by adrperez          #+#    #+#             */
/*   Updated: 2022/11/10 12:15:57 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*concat_lines(char *original, char *new_line)
{
	size_t	len;
	char	*concat;
	
	len = ft_strlen(original) + ft_strlen(new_line);
	concat = ft_calloc(len + 1, sizeof(char));
	if (!concat)
		return (NULL);
	concat = ft_strjoin(original, new_line);
	printf("===%s\n",concat);
	return (concat);		
}

char	*ft_read(int fd, char *buffer)
{
	int bytes;
	printf("===buffer:%s\n", buffer);
	bytes = read(fd, buffer, BUFFER_SIZE);
	printf("===Bytes:%d\n", bytes);
	if (bytes < BUFFER_SIZE)
		buffer[bytes] = 0;
	else
		buffer[BUFFER_SIZE] = 0;
	return (buffer);
}

char *get_next_line(int fd)
{
	char		*line;
	static char	*buffer;
	
	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if(!buffer)
		return (NULL);
	while (!line || !ft_strchr(line, '\n'))
	{
		buffer = ft_read(fd, buffer);
		if(!buffer)
			return (line);
		line = concat_lines(line, buffer);
	}
	return (line);
}
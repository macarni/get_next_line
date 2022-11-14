/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:49:07 by adrperez          #+#    #+#             */
/*   Updated: 2022/11/14 14:20:58 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*concat_lines(char *original, char *new_line)
{
	size_t	len;
	char	*concat;
	
	
	len = ft_strlen(original) + ft_strlen(new_line);
	concat = malloc((len + 1) * sizeof(char));
	if (!concat)
		return (NULL);
	//printf("join: %s\n", original);
	concat = ft_strjoin(original, new_line);
	//printf("===%s\n",concat);
	return (concat);		
}

char	*ft_read(int fd, char *buffer)
{
	int bytes;
	
	bytes = read(fd, buffer, BUFFER_SIZE);
	//printf("===Buffer:%s\n", buffer);
	if (bytes < BUFFER_SIZE)
		buffer[bytes] = 0;
	else
		buffer[BUFFER_SIZE] = 0;
	//printf("===buffer:%s\n", buffer);
	return (buffer);
}

char *get_next_line(int fd)
{
	char		*line;
	static char	*buffer;
	
	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if(!buffer)
		return (NULL);
	while (!line || !ft_strchr(line, '\n'))
	{
		if (!*buffer)
		{
			buffer = ft_read(fd, buffer);
			printf("buffer:%s\n", buffer);
			if(!buffer)
				return (line);
		}
		//printf("line: %s\n", line);
		line = concat_lines(line, buffer);
		printf("===line:%s\n", buffer);
		printf("===buffer:%s\n", buffer);
	}
	return (line);
}
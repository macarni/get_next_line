/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:49:07 by adrperez          #+#    #+#             */
/*   Updated: 2022/11/10 15:43:51 by adrperez         ###   ########.fr       */
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
	// printf("join: %s\n", original);
	concat = ft_strjoin(original, new_line);
	// printf("===%s\n",concat);
	return (concat);		
}

char	*delete_new_line(char *buffer)
{
	int	i;

	i = 0;
	while(buffer[i] != '\n')
		i++;
	buffer[++i] = 0; //la siguiente despues del \n tiene que ser un 0
	return (buffer);
}

char	*ft_read(int fd, char *buffer)
{
	int bytes;
	// printf("===buffer:%s\n", buffer);
	bytes = read(fd, buffer, BUFFER_SIZE);
	// printf("===Bytes:%d\n", bytes);
	if (ft_strchr(buffer, '\n'))
		buffer = delete_new_line(buffer);
	else 
	{
		if (bytes < BUFFER_SIZE)
			buffer[bytes] = 0;
		else
			buffer[BUFFER_SIZE] = 0;
	}
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
		// printf("line: %s\n", line);
		line = concat_lines(line, buffer);
	}
	//Si lee un salto de linea y no está en el numero maximo del buffer_size, sigue leyendo: hay que decirle que pare de leer al leer el \n
	return (line);
}
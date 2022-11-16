/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:49:07 by adrperez          #+#    #+#             */
/*   Updated: 2022/11/16 14:20:00 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*prepare_line(char *buffer)
{
	size_t	len;
	char	*line;
	
	len = 0;
	while (buffer && buffer[len] != '\n')
		len++;
	len++;
	line = ft_calloc((len + 1), sizeof(char));
	if (!line)
		return (NULL); 
	line = ft_memcpy(line, buffer, len);
	return (line);		
}

char	*ft_read(int fd, char *buffer)
{
	int		bytes;
	char	*aux;

	bytes = 1;
	printf("==buffer: %s\n", buffer);
	printf("==buffer_mem: %p\n", &buffer);
	aux = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	while (bytes != 0) //si llega a cero ha terminado el archivo
	{
		bytes = read(fd, aux, BUFFER_SIZE);
		//aux = ft_calloc((BUFFER_SIZE + ft_strlen(aux) + 1), sizeof(char));
		printf("Aux: %s\n", aux);
		buffer = ft_strjoin(buffer, aux);
		printf("Aux: %s\n", aux);
		
		if (ft_strchr(buffer, '\n'))
			break;
	}
	free(aux);
	return (buffer);
}

char	*prepare_buffer(char *buffer)
{
	char	*buffer_no_line;
	char	*aux;
	size_t	len_buffer;
	size_t		i;

	i = 0;
	len_buffer = 0;
	aux = ft_memchr(buffer, '\n', ft_strlen(buffer));
	aux++;
	len_buffer = ft_strlen(aux);
	buffer_no_line = ft_calloc((len_buffer + 1), sizeof(char));
	while (i < len_buffer)
	{
		buffer_no_line[i] = aux[i];
		i++;
	}
	printf("buffer_no_line: %s\n", buffer_no_line);
	printf("buffer: %s\n", buffer);
	free(buffer);
	return (buffer_no_line);
}

char *get_next_line(int fd)
{
	char		*line;
	static char	*buffer;
	
	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	//1. Leer buffer (de BS en BS) hasta \n --> concatenamos buffers
	printf("==buffer: %s\n", buffer);
	if(!*buffer)
		buffer = ft_read(fd, buffer);
	//2. Copiar en line el buffer hasta \n
	line = prepare_line(buffer);
	//3. Preparar buffer para que apunte al caracter después del \n
	buffer = prepare_buffer(buffer);
	return (line);
}
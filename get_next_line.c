/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:49:07 by adrperez          #+#    #+#             */
/*   Updated: 2022/11/16 11:25:24 by adrperez         ###   ########.fr       */
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
	while (bytes != 0) //si llega a cero ha terminado el archivo
	{
		buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		bytes = read(fd, buffer, BUFFER_SIZE);
		//aux = ft_calloc((BUFFER_SIZE + ft_strlen(aux) + 1), sizeof(char));
		printf("Aux: %s\n", aux);
		aux = ft_strjoin(aux, buffer);
		printf("Aux: %s\n", aux);
		if (ft_strchr(buffer, '\n'))
			return(aux);
	}
	free(buffer);
	return (aux);
}

char	*prepare_buffer(char *buffer)
{
	char	*buffer_no_line;
	size_t	len;
	size_t	len_buffer;

	len = 0;
	len_buffer = 0;
	while (buffer && *buffer != '\n')
		buffer++;
	buffer++;
	printf("Buffer: %s\n", buffer);
	len_buffer = ft_strlen(buffer);
	buffer_no_line = ft_calloc((len_buffer + 1), sizeof(char));
	buffer_no_line = ft_strjoin(buffer_no_line, buffer);
	//free(buffer);
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
	buffer = ft_read(fd, buffer);
	//2. Copiar en line el buffer hasta \n
	line = prepare_line(buffer);
	//3. Preparar buffer para que apunte al caracter después del \n
	buffer = prepare_buffer(buffer);
	return (line);
}
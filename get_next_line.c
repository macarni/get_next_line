/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:49:07 by adrperez          #+#    #+#             */
/*   Updated: 2022/12/14 17:29:34 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * It reads the file and returns a string with the content of the file
 * 
 * @param fd file descriptor
 * @param buffer This is the buffer that will be returned.
 * 
 * @return a pointer to the first character of the string.
 * Tenemos que liberar aux porque si tiene contenido y lo reutilizamos, puede que se impriman caracteres que ya no están en lo nuevo que ha leido
 * 
 */
char	*ft_read(int fd, char *buffer)
{
	int		bytes;
	char	*aux;

	bytes = 1;
	if (!buffer)
		buffer = ft_calloc(1, 1);
	while (bytes != 0) //si llega a cero ha terminado el archivo
	{
		aux = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		bytes = read(fd, aux, BUFFER_SIZE);
		buffer = get_buffer(buffer, aux);
		if (ft_strchr(aux, '\n'))
			bytes = 0;
		free(aux);
	}
	return (buffer);
}

char	*get_buffer(char *old_buffer, char	*new_buffer)
{
	char	*aux;

	aux = ft_strjoin(old_buffer, new_buffer);
	free(old_buffer);
	return (aux);
}

char	*prepare_line(char *buffer)
{
	int		len;
	char	*line;
	int		i;
	
	len = 0;
	i = 0;
	if (buffer[i] == '\0')
		return (0);
	while (buffer[len] && buffer[len] != '\n')
		len++;
	line = ft_calloc((++len + 1), sizeof(char));
	if (!line)
		return (NULL); 
	while (len > 0)
	{
		((char *)line)[i] = ((char *)buffer)[i];
		i++;
		len--;
	}
	return (line);		
}

char	*prepare_buffer(char *buffer)
{
	char	*buffer_no_line;
	char	*aux;
	int		len_buffer;
	int		i;

	i = 0;
	len_buffer = 0;
	aux = ft_memchr(buffer, '\n', ft_strlen(buffer));
	if (!aux || !buffer)
	{
		free(buffer);
		return (NULL);
	}
	aux++;
	len_buffer = ft_strlen(aux);
	buffer_no_line = ft_calloc((len_buffer + 1), sizeof(char));
	while (i < len_buffer && aux[i])
	{
		buffer_no_line[i] = aux[i];
		i++;
	}
	free(buffer);
	return (buffer_no_line);
}

/**
 * Read the buffer until a newline is found, copy the buffer until the newline into a new string, and
 * prepare the buffer for the next call
 * 
 * @param fd file descriptor
 * 
 * @return A pointer to the first character of the line.
 * Con read(fd, 0, 0) < 0 vemos si hay algún error --> Le estamos diciendo que lea 0 bytes por lo que tendría que devolver que ha leido cero pero si hay algún error, devuelve negativo. Por lo tanto, si ha habido error y el buffer tiene conteido hay que liberarlo y ponerlo a NULL porque el free no pone el contenido a nulo y estaría lleno de contenido random. 
 */

char *get_next_line(int fd)
{
	char		*line;
	static char	*buffer;
	
	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		if (buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	//1. Leer buffer (de BS en BS) hasta \n --> concatenamos buffers
	buffer = ft_read(fd, buffer);
	//2. Copiar en line el buffer hasta \n smhajk
	line = prepare_line(buffer);
	//3. Preparar buffer para que apunte al caracter después del \n
	buffer = prepare_buffer(buffer);
	return (line);
}
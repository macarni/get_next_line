/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:49:07 by adrperez          #+#    #+#             */
/*   Updated: 2022/12/19 10:43:49 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * It reads the file and returns a string with the content 
 * of the file
 * @param fd file descriptor
 * @param buffer This is the buffer that will be returned.
 * 
 * @return a pointer to the first character of the string.
 * Tenemos que liberar aux porque si tiene contenido y lo 
 * reutilizamos, puede que se impriman caracteres que ya no 
 * están en lo nuevo que ha leido
 * byes != 0 -> si llega a cero ha terminado el archivo
 * 
 * READ Function: 
 * Input parameters: int fd file descriptor is an integer 
 * and not a file pointer. The file descriptor for stdin is 0
 * void buf pointer to buffer to store characters read by the read function
 * size_t count maximum number of characters to read
 * Note.: a character is equivalent to a 1 byte and a byte is made up of 8 bits therefore a character is made up of 8 bits (1 byte)
 * 
 */
char	*ft_read(int fd, char *buffer)
{
	int		bytes;
	char	*aux;

	bytes = 1;
	if (!buffer)
		buffer = ft_calloc(1, 1);
	while (bytes != 0)
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

/**
 * It takes two strings, joins them, frees the first one, 
 * and returns the second one
 * 
 * @param old_buffer the buffer that was already 
 * read from the file descriptor
 * @param new_buffer the buffer that was just read 
 * from the file descriptor (aux)
 * 
 * @return A pointer to a string.
 */
char	*get_buffer(char *old_buffer, char	*new_buffer)
{
	char	*aux;

	aux = ft_strjoin(old_buffer, new_buffer);
	free(old_buffer);
	return (aux);
}

/**
 * This function takes a buffer and returns a line
 * 
 * @param buffer This is the buffer that we're reading from.
 * 
 * @return A line that will be printed
 */
char	*prepare_line(char *buffer)
{
	int		len;
	char	*line;
	int		i;

	len = 0;
	i = 0;
	if (!buffer[i])
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

/**
 * It takes a string and returns a string that is 
 * the same string without the first line
 * 
 * @param buffer the buffer that contains the line 
 * and the rest of the file
 * 
 * @return a pointer to a new string that contains the 
 * rest of the buffer after the newline character.
 */
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
 * Read the buffer (of BUFFER_SIZE bytes) until a newline 
 * character is found, concatenate the buffers,
 * copy the buffer until the newline character into a 
 * new string, and prepare the buffer to point to
 * the character after the newline character
 * 
 * Con read(fd, 0, 0) < 0 vemos si hay algún error --> Le 
 * estamos diciendo que lea 0 bytes por lo que tendría que 
 * devolver que ha leido cero pero si hay algún error, devuelve 
 * negativo. Por lo tanto, si ha habido error y el buffer tiene 
 * conteido hay que liberarlo y ponerlo a NULL porque el free 
 * no pone el contenido a nulo y estaría lleno de contenido random.
 * 
 * //1. Leer buffer (de BS en BS) hasta \n --> concatenamos buffers
 * //2. Copiar en line el buffer hasta \n
 * //3. Preparar buffer para que apunte al caracter después del \n
 * 
 * @param fd file descriptor
 * 
 * @return A pointer to the first character of the line.
 */
char	*get_next_line(int fd)
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
	buffer = ft_read(fd, buffer);
	line = prepare_line(buffer);
	buffer = prepare_buffer(buffer);
	return (line);
}

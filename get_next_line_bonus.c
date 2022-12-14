/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:49:07 by adrperez          #+#    #+#             */
/*   Updated: 2022/12/19 11:52:06 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer[OPEN_MAX];

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		if (buffer[fd])
		{
			free(buffer[fd]);
			buffer[fd] = NULL;
		}
		return (NULL);
	}
	buffer[fd] = ft_read(fd, buffer[fd]);
	line = prepare_line(buffer[fd]);
	buffer[fd] = prepare_buffer(buffer[fd]);
	return (line);
}

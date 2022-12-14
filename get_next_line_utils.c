/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:46:30 by adrperez          #+#    #+#             */
/*   Updated: 2022/12/19 12:39:31 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}	
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*pointer;
	int		num;
	int		i;

	i = 0;
	num = count * size;
	if (num == 1 && count != 1)
		return (NULL);
	pointer = malloc(num);
	if (!pointer)
		return (0);
	while (i < num)
	{
		pointer[i] = '\0';
		i++;
	}
	return ((void *)pointer);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * It takes two strings, concatenates them, and returns the result
 * 
 * @param s1 The first string to be concatenated.
 * @param s2 The string to be appended to the end of s1.
 * 
 * @return A pointer to a string.
 */
char	*ft_strjoin(char *s1, char *s2)
{
	char	*concat;
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s2)
		return ((char *)s1);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (len == 0)
		return (NULL);
	concat = ft_calloc(len, sizeof(char));
	if (!concat)
		return (NULL);
	while (s1[i])
	{
		concat[i] = s1[i];
		i++;
	}
	while (s2[j])
		concat[i++] = s2[j++];
	concat[i] = '\0';
	return (concat);
}

/**
 * The function ft_memchr() locates the first occurrence of c 
 * (converted to an unsigned char) in string
 * 
 * @param s This is the pointer to the first byte of the memory area.
 * @param c The character to search for.
 * @param n The number of bytes to be searched.
 * 
 * @return The address of the first occurrence of the 
 * character c in the first n bytes of the string
 * pointed to by s.
 */
void	*ft_memchr(void *s, int c, size_t n)
{
	unsigned char	*aux;

	aux = (unsigned char *)s;
	while (n > 0)
	{
		if (*aux == (unsigned char)c)
			return (aux);
		aux++;
		n--;
	}	
	return (0);
}

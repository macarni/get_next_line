/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:46:30 by adrperez          #+#    #+#             */
/*   Updated: 2022/11/14 14:17:38 by adrperez         ###   ########.fr       */
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
	void	*pointer;
	int		num;

	num = count * size;
	if (num == 1 && count != 1)
		return (NULL);
	pointer = malloc(num);
	if (!pointer)
		return (0);
	while (num > 0)
	{
		num--;
		*(char *)pointer = 0;
		pointer++;
	}
	return (pointer);
}

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*concat;
	size_t		len;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	// printf("s1: %s\n", s1);
	// printf("s2: %s\n", s2);
	// printf("len: %zu\n", len);
	if (len == 0)
		return (NULL);
	concat = ft_calloc(len, sizeof(char));
	if (!concat)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			concat[i] = s1[i];
			// if (concat[i] == '\n')
			// {
			// 	//printf("concat: %s\n", concat);
			// 	return (concat);
			// }
			i++;
		}
	}
	while(s2[j])
	{	
		concat[i] = s2[j];
		// if (concat[i] == '\n')
		// {
		// 	//printf("concat: %s\n", concat);
		// 	return (concat);
		// }
		i++;
		j++;
	}
	// printf("concat: %s\n", concat);
	return (concat);
}
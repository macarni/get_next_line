/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:46:30 by adrperez          #+#    #+#             */
/*   Updated: 2022/11/07 14:46:16 by adrperez         ###   ########.fr       */
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
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (len == 0)
		return (NULL);
	concat = ft_calloc(len, sizeof(char));
	if (!concat)
		return (NULL);
	while (s1[i])
		concat[i] = s1[i++];
	while(s2[j])
		concat[i++] = s2[j++];
	return (concat);
}

// size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
// {
// 	size_t	i;
// 	size_t	j;
// 	size_t	dst_size;
// 	size_t	src_size;

// 	if (!dst && dstsize == 0)
// 		return (0);
// 	j = 0;
// 	i = 0;
// 	dst_size = ft_strlen(dst);
// 	i = dst_size;
// 	src_size = ft_strlen(src);
// 	if (dstsize <= dst_size)
// 		return (src_size + dstsize);
// 	while (src[j] && j < dstsize - dst_size - 1)
// 	{
// 		dst[i] = src[j];
// 		j++;
// 		i++;
// 	}
// 	dst[i] = '\0';
// 	return (src_size + dst_size);
// }
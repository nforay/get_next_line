/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 17:07:09 by nforay            #+#    #+#             */
/*   Updated: 2020/01/06 23:37:43 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t 	ft_strlentoc(const char *str, int c)
{
	size_t i;

	i = 0;
	if (!(str))
		return (0);
	while (str[i] && (str[i] != c))
		i++;
	if (str[i] == c)
		return (i);
	return (i);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	d = dest;
	s = src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (!s)
		return (NULL);
	if (ft_strlentoc(s, 0) < (size_t)start)
		return (ft_strdup(""));
	if (!(ptr = malloc(len + 1)))
		return (NULL);
	s += start;
	ft_memcpy(ptr, s, len);
	ptr[len] = '\0';
 	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	t1;
	size_t	t2;

	if (!s1 || !s2)
		return (NULL);
	t1 = ft_strlen(s1);
	t2 = ft_strlen(s2);
	if (!(ptr = malloc(t1 + t2 + 1)))
		return (NULL);
	ft_memcpy(ptr, s1, t1);
	ft_memcpy((ptr + t1), s2, t2);
	ptr[(t1 + t2)] = '\0';
	return (ptr);
}

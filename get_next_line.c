/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 17:07:15 by nforay            #+#    #+#             */
/*   Updated: 2020/01/06 23:38:28 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strdup(const char *src)
{
	char	*pointeur;
	int		i;

	i = 0;
	while (src[i])
		i++;
	if (!(pointeur = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		pointeur[i] = src[i];
		i++;
	}
	pointeur[i] = '\0';
	return (pointeur);
}

static int	verif(int fd, char **reading, char **line)
{
	if (BUFFER_SIZE < 1 || fd == -1 || !line 
			|| (!(reading[fd]) && !(reading[fd] = ft_strdup(""))))
		return (0);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	size_t		ret;
	static char	*reading[4000];
	char		buf[BUFFER_SIZE + 1];
	char		*cpy;

	if ((read(fd, buf, 0) == -1) || !verif(fd, reading, line))
		return (-1);
	while ((ft_strlentoc(reading[fd], '\n') == (ft_strlen(reading[fd])))
		&& (ret = read(fd, buf, BUFFER_SIZE)))
	{
		buf[ret] = '\0';
		cpy = ft_strjoin(reading[fd], buf);
		free(reading[fd]);
		reading[fd] = cpy;
	}
	*line = ft_substr(reading[fd], 0, ft_strlentoc(reading[fd], '\n'));
	if (*reading[fd])
	{
		ret = (ft_strlen(reading[fd]) - ft_strlentoc(reading[fd], '\n'));
		cpy = ft_substr(reading[fd], ft_strlentoc(reading[fd], '\n') + 1, ret);
		free(reading[fd]);
		reading[fd] = cpy;
		return (1);
	}
	return (0);
}

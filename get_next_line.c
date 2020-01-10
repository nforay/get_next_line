/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 17:07:15 by nforay            #+#    #+#             */
/*   Updated: 2020/01/10 19:23:52 by nforay           ###   ########.fr       */
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

static int	verif(int fd, char **tmp, char **line)
{
	if (BUFFER_SIZE < 1 || fd == -1 || !line 
			|| (!(tmp[fd]) && !(tmp[fd] = ft_strdup(""))))
		return (0);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	size_t		ret;
	static char	*tmp[4000];
	char		buf[BUFFER_SIZE + 1];
	char		*cpy;

	if ((read(fd, buf, 0) == -1) || !verif(fd, tmp, line))
		return (-1);
	while (!(ft_strlentoc(tmp[fd], '\n')) && (ret = read(fd, buf, BUFFER_SIZE)))
	{
		buf[ret] = '\0';
		cpy = ft_strjoin(tmp[fd], buf);
		free(tmp[fd]);
		tmp[fd] = cpy;
	}
	*line = ft_substr(tmp[fd], 0, ft_strlentoc(tmp[fd], '\n'));
	if (*tmp[fd] && ((ft_strlentoc(tmp[fd], '\n'))))
	{
		ret = (ft_strlen(tmp[fd]) - ft_strlentoc(tmp[fd], '\n'));
		cpy = ft_substr(tmp[fd], ft_strlentoc(tmp[fd], '\n') + 1, ret);
		free(tmp[fd]);
		tmp[fd] = cpy;
		return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 17:07:15 by nforay            #+#    #+#             */
/*   Updated: 2020/02/02 15:17:13 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char		*ft_strdup(const char *src)
{
	char	*ptr;
	int		i;

	i = 0;
	while (src[i])
		i++;
	if (!(ptr = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static int	check_vars(int fd, char **tmp, char **line)
{
	if (BUFFER_SIZE < 1 || fd == -1 || !line
			|| (!(tmp[fd]) && !(tmp[fd] = ft_strdup(""))))
		return (0);
	return (1);
}

static int	line_found(const char *str)
{
	size_t i;

	i = 0;
	if (!(str))
		return (0);
	while (str[i])
		if (str[i++] == '\n')
			return (1);
	return (0);
}

void		ft_strdel(char **str)
{
	if (!str)
		return ;
	free(*str);
	*str = NULL;
}

int			get_next_line(int fd, char **line)
{
	size_t		ret;
	static char	*tmp[4096];
	char		buf[BUFFER_SIZE + 1];
	char		*cpy;

	if ((read(fd, buf, 0) == -1) || !check_vars(fd, tmp, line))
		return (-1);
	while ((!(line_found(tmp[fd]))) && (ret = read(fd, buf, BUFFER_SIZE)))
	{
		buf[ret] = '\0';
		cpy = ft_strjoin(tmp[fd], buf);
		free(tmp[fd]);
		tmp[fd] = cpy;
	}
	*line = ft_substr(tmp[fd], 0, ft_strlentoc(tmp[fd], '\n'));
	if (*tmp[fd])
	{
		ret = (ft_strlen(tmp[fd]) - ft_strlentoc(tmp[fd], '\n'));
		cpy = ft_substr(tmp[fd], ft_strlentoc(tmp[fd], '\n') + 1, ret);
		free(tmp[fd]);
		tmp[fd] = cpy;
		return (1);
	}
	ft_strdel(&tmp[fd]);
	return (0);
}

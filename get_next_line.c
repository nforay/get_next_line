/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 17:07:15 by nforay            #+#    #+#             */
/*   Updated: 2020/02/07 23:22:32 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char		*ft_clipstr(char **src, int c)
{
	char	*ptr;
	size_t	len;
	size_t	offset;

	offset = ft_strlentoc(*src, c);
	len = ft_strlen(*src);
	if (!(ptr = malloc(len - offset + 1)))
		return (NULL);
	len -= offset;
	ptr[len] = '\0';
	while (len--)
		ptr[len] = (*src)[offset + len + 1];
	ft_strdel(src);
	*src = ptr;
	return (ptr);
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

	if ((read(fd, buf, 0) == -1) || BUFFER_SIZE < 1 || fd == -1 || !line
			|| (!(tmp[fd]) && !(tmp[fd] = ft_strdup(""))))
		return (-1);
	while ((!(line_found(tmp[fd]))) && (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		ft_strmerge(&tmp[fd], buf);
	}
	*line = ft_substr(tmp[fd], 0, ft_strlentoc(tmp[fd], '\n'));
	ret = line_found(tmp[fd]);
	ft_clipstr(&tmp[fd], '\n');
	if (!ret)
		ft_strdel(&tmp[fd]);
	return (ret);
}

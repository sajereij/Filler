/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:26:00 by sreijola          #+#    #+#             */
/*   Updated: 2020/10/14 14:49:04 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/get_next_line.h"

static int	ft_find_line(char **aof, char **line, const int fd)
{
	int			i;
	char		*temp;

	i = 0;
	while (aof[fd][i] != '\n' && aof[fd][i] != '\0')
		i++;
	if (aof[fd][i] == '\n')
	{
		if (!(*line = ft_strsub(aof[fd], 0, i)))
			return (-1);
		if (!(temp = ft_strdup(aof[fd] + i + 1)))
			return (-1);
		free(aof[fd]);
		aof[fd] = temp;
	}
	else
	{
		if (!(*line = ft_strdup(aof[fd])))
			return (-1);
		aof[fd][0] = '\0';
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*aof[FD_MAX];
	ssize_t		ret;
	char		buff[BUFF_SIZE + 1];

	ret = 0;
	if (!line || fd < 0 || fd > FD_MAX || BUFF_SIZE < 1 \
			|| read(fd, buff, 0) < 0)
		return (-1);
	if (aof[fd] == NULL && !(aof[fd] = ft_strnew(0)))
		return (-1);
	while ((ft_strchr(aof[fd], '\n') == NULL) \
			&& (ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if (!(aof[fd] = ft_strjoin_free(aof[fd], buff, 1)))
			return (-1);
	}
	if (ret == 0 && aof[fd][0] == '\0')
		return (0);
	return (ft_find_line(aof, line, fd));
}

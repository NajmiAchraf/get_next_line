/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:13:21 by anajmi            #+#    #+#             */
/*   Updated: 2021/12/05 11:48:32 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line(char *line, char **save, char *buffer)
{
	freeing(&buffer);
	if (!*save || ft_strlen(*save) == 0)
		return (NULL);
	else if (ft_strchr(*save, '\n'))
		line = ft_substr(*save, 0,
				ft_strlen(*save) - ft_strlen(ft_strchr(*save, '\n')) + 1);
	else
		line = ft_substr(*save, 0, ft_strlen(*save));
	return (line);
}

char	*get_save(char **save)
{
	char	*tmp;

	tmp = NULL;
	if (!*save)
		return (NULL);
	if (ft_strchr(*save, '\n'))
		tmp = ft_substr(ft_strchr(*save, '\n') + 1, 0,
				ft_strlen(ft_strchr(*save, '\n')));
	else
	{
		freeing(save);
		return (NULL);
	}
	freeing(save);
	return (tmp);
}

void	freeing(char **to_free)
{
	free(*to_free);
	*to_free = NULL;
}

char	*error(char *buffer, char **save, int fd)
{
	freeing(&buffer);
	freeing(&save[fd]);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*buffer;
	char		*line;
	int			readsize;

	line = NULL;
	readsize = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!save[fd])
		save[fd] = ft_substr("", 0, 1);
	while (readsize > 0 && !ft_strchr(save[fd], '\n'))
	{
		readsize = read(fd, buffer, BUFFER_SIZE);
		if (readsize < 0)
			return (error(buffer, save, fd));
		save[fd] = ft_strjoin(save[fd], buffer, readsize);
	}
	line = get_line(line, &save[fd], buffer);
	save[fd] = get_save(&save[fd]);
	return (line);
}

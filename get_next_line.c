/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolemai <edolemai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 15:30:50 by edolemai          #+#    #+#             */
/*   Updated: 2026/11/24 08:43:26 by edolemai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_checkstash(ssize_t bytes_read, char **stash)
{
	char	*new_stash;

	if (bytes_read == -1)
	{
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	if (bytes_read == 0)
	{
		if (!*stash || !**stash)
		{
			free(*stash);
			*stash = NULL;
			return (NULL);
		}
		new_stash = ft_substr(*stash, 0, ft_strlen(*stash));
		if (!new_stash)
			return (NULL);
		free(*stash);
		*stash = NULL;
		return (new_stash);
	}
	return (*stash);
}

static char	*ft_checkline(char **stash, char *line)
{
	size_t	len;
	char	*new_stash;

	len = 0;
	while ((*stash)[len] && (*stash)[len] != '\n')
		len++;
	line = ft_substr(*stash, 0, len + 1);
	if (!line)
		return (NULL);
	new_stash = ft_substr(*stash, len + 1, ft_strlen(*stash) - (len + 1));
	if (!new_stash)
	{
		free(line);
		return (NULL);
	}
	free(*stash);
	*stash = new_stash;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	ssize_t		bytes_read;
	char		buffer[BUFFER_SIZE + 1];
	char		*new_stash;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!stash || !ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			line = ft_checkstash(bytes_read, &stash);
			return (line);
		}
		buffer[bytes_read] = '\0';
		new_stash = ft_strjoin(stash, buffer);
		if (!new_stash)
			return (NULL);
		free(stash);
		stash = new_stash;
	}
	return (line = ft_checkline(&stash, line));
}

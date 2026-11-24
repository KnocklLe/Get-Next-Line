/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolemai <edolemai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 13:56:20 by edolemai          #+#    #+#             */
/*   Updated: 2026/11/24 15:18:00 by edolemai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*finalstring;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	if (!s1)
		s1 = "";
	finalstring = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!finalstring)
		return (NULL);
	while (s1[i])
	{
		finalstring[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		finalstring[i + j] = s2[j];
		j++;
	}
	finalstring[i + j] = '\0';
	return (finalstring);
}

char	*ft_free(char **stash)
{
	free(*stash);
	*stash = NULL;
	return (NULL);
}

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
			return (ft_free(stash));
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
		return (ft_free(stash));
	}
	if (!*new_stash)
	{
		free(new_stash);
		new_stash = NULL;
	}
	free(*stash);
	*stash = new_stash;
	return (line);
}

char	*get_next_line_bonus(int fd)
{
	static char	*stash[OPEN_MAX];
	ssize_t		bytes_read;
	char		buffer[BUFFER_SIZE + 1];
	char		*new_stash;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	while (!stash[fd] || !ft_strchr(stash[fd], '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (ft_checkstash(bytes_read, &stash[fd]));
		buffer[bytes_read] = '\0';
		new_stash = ft_strjoin(stash[fd], buffer);
		if (!new_stash)
			return (ft_free(&stash[fd]));
		free(stash[fd]);
		stash[fd] = new_stash;
	}
	return (ft_checkline(&stash[fd], NULL));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolemai <edolemai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 15:30:50 by edolemai          #+#    #+#             */
/*   Updated: 2026/11/18 16:56:07 by edolemai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_openfile(int fd)
{
	int			bytes_read;
	char		buffer[BUFFER_SIZE];
	static int	i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		while (i)
		{
			if (i == '\0')
				return (buffer + i);
			write(1, buffer, i);
			i++;
		}
	}
	return ("test");
}

char	*get_next_line(int fd)
{
	char *next_line;

	next_line = malloc(sizeof(char) * BUFFER_SIZE);
	ft_openfile(fd);

	close(fd);
	return ("NULL");
}
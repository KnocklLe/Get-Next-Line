/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolemai <edolemai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 15:30:50 by edolemai          #+#    #+#             */
/*   Updated: 2026/11/23 14:25:17 by edolemai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_print(char *buffer)
{
	static int	i;

	while (i < BUFFER_SIZE)
	{
		if (buffer[i] == '\n')
		{
			i++;
			ft_putchar('\n');
			return ;
		}
		ft_putchar(buffer[i]);
		i++;
	}
}

static int	ft_openfile(int fd)
{
	int			bytes_read;
	char		buffer[BUFFER_SIZE];

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	ft_print(buffer);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	char *next_line;

	next_line = malloc(sizeof(char) * BUFFER_SIZE);
	ft_openfile(fd);
	close(fd);
	return (next_line);
}
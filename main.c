/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolemai <edolemai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 15:37:42 by edolemai          #+#    #+#             */
/*   Updated: 2026/11/24 14:07:47 by edolemai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <stdio.h>

int	main(void)
{

	// {
	// 	int		fd;
	// 	int		fd2;
	// 	char	*line;
	// 	char	*line2;
	// 	fd = open("test.txt", O_RDONLY);
	// 	fd2 = open("test2.txt", O_RDONLY);
	// 	line = get_next_line(fd);
	// 	line2 = get_next_line(fd2);
	// 	while (line)
	// 	{
	// 		printf("Fichier 1 : %s", line);
	// 		free(line);
	// 		line = get_next_line(fd);
	// 	}
	// 	printf("\n======second file======\n");
	// 	while (line2)
	// 	{
	// 		printf("Fichier 2 : %s", line2);
	// 		free(line2);
	// 		line2 = get_next_line(fd2);
	// 	}
	// 	close(fd);
	// 	close(fd2);
	// }
	{
		int		fd;
		int		fd2;
		char	*line;
		char	*line2;
		fd = open("test.txt", O_RDONLY);
		fd2 = open("test2.txt", O_RDONLY);
		line = get_next_line_bonus(fd);
		line2 = get_next_line_bonus(fd2);
		while (line)
		{
			printf("Fichier 1 bonus: %s", line);
			free(line);
			line = get_next_line_bonus(fd);
		}
		printf("\n======second file======\n");
		while (line2)
		{
			printf("Fichier 2 bonus: %s", line2);
			free(line2);
			line2 = get_next_line_bonus(fd2);
		}
		close(fd);
		close(fd2);
	}
	return (0);
}

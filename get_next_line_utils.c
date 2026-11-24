/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolemai <edolemai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 15:30:52 by edolemai          #+#    #+#             */
/*   Updated: 2026/11/24 08:43:45 by edolemai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_size;
	char	*finalstring;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (s2 == NULL)
		return (NULL);
	if (s1)
	{
		total_size = ft_strlen(s1) + ft_strlen(s2);
		finalstring = malloc(sizeof(char) * (total_size + 1));
		if (finalstring == NULL)
			return (NULL);
		while (s1[i])
		{
			finalstring[i] = s1[i];
			i++;
		}
	}
	else
	{
		finalstring = malloc(sizeof(char) * (ft_strlen(s2) + 1));
		if (!finalstring)
			return (NULL);
	}
	while (s2[j])
	{
		finalstring[i + j] = s2[j];
		j++;
	}
	finalstring[i + j] = '\0';
	return (finalstring);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

static char	*ft_strdup(const char *s)
{
	int		len;
	char	*dest;
	int		i;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	dest = malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *dest;
	size_t i;
	size_t s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:18:15 by rammisse          #+#    #+#             */
/*   Updated: 2025/02/03 14:16:42 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	else
		return (NULL);
}

char	*readline(int fd, char *str)
{
	char	*buffer;
	ssize_t	bytes;

	bytes = 1;
	buffer = (char *)malloc((size_t)BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	while (bytes > 0 && !ft_strchr(str, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[bytes] = '\0';
		str = ft_strjoin(str, buffer);
		if (!str)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (str);
}

char	*extractline(char *str)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	j = 0;
	if (!str || !*str)
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	line = (char *)malloc(i + 1 * sizeof(char));
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = str[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*getremainder(char *str)
{
	char	*tempbuff;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	tempbuff = (char *)malloc(((ft_strlen(str) - i) + 1) * sizeof(char));
	if (!tempbuff)
		return (free(str), NULL);
	i++;
	while (str[i])
		tempbuff[j++] = str[i++];
	tempbuff[j] = '\0';
	free(str);
	return (tempbuff);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	str = readline(fd, str);
	if (!str)
		return (NULL);
	line = extractline(str);
	str = getremainder(str);
	return (line);
}

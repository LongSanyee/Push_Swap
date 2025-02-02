/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:42:11 by rammisse          #+#    #+#             */
/*   Updated: 2025/02/01 21:17:42 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	erro(void)
{
	write (1, "Error\n", 6);
	exit(0);
}

static size_t	countsubstring(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int	wordlen(char *s, char sep)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != sep)
		i++;
	return (i);
}

static char	**freeall(char **c, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(c[i]);
		i++;
	}
	free(c);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	*str;
	char	**strarr;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)s;
	strarr = (char **)malloc((countsubstring(s, c) + 1) * sizeof(char *));
	if (!strarr)
		return (NULL);
	while (i < countsubstring(s, c))
	{
		while (*str == c)
			str++;
		strarr[i] = (char *)malloc((wordlen(str, c) + 1) * (sizeof(char)));
		if (!strarr[i])
			return (freeall(strarr, i));
		ft_strlcpy(strarr[i], str, (wordlen(str, c) + 1));
		str = str + wordlen(str, c);
		i++;
	}
	strarr[i] = NULL;
	return (strarr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:03:20 by rammisse          #+#    #+#             */
/*   Updated: 2025/02/03 20:50:45 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int	strval(char **str)
{
	if (!str[0])
	{
		free_split(str);
		return (0);
	}
	return (1);
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*ptr1;

	ptr = (unsigned char *)str1;
	ptr1 = (unsigned char *)str2;
	i = 0;
	if (n == 0)
		return (0);
	while ((str1[i] != '\0' || str2[i] != '\0')
		&& str1[i] == str2[i] && i < n - 1)
	{
		i++;
	}
	return (ptr[i] - ptr1[i]);
}

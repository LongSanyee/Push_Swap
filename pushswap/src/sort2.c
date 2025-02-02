/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:01:00 by rammisse          #+#    #+#             */
/*   Updated: 2025/02/02 11:32:05 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	*copynode(t_stack **a)
{
	int		i;
	int		*str;
	t_stack	*temp;

	i = 0;
	str = malloc(ft_lstsize(*a) * sizeof(int));
	if (!str)
		return (0);
	temp = *a;
	while (temp)
	{
		str[i] = temp->content;
		temp = temp->next;
		i++;
	}
	return (str);
}

void	sortarr(int *arr, int n)
{
	int	j;
	int	temp;
	int	i;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	assignindex(t_stack **a)
{
	t_stack	*temp;
	int		*arr;
	int		i;

	arr = copynode(a);
	sortarr(arr, ft_lstsize(*a));
	i = 0;
	temp = *a;
	while (temp)
	{
		i = 0;
		while (i < ft_lstsize(*a))
		{
			if (arr[i] == temp->content)
				temp->index = i;
			i++;
		}
		temp = temp->next;
	}
	free(arr);
}

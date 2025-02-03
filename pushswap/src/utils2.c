/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:03:20 by rammisse          #+#    #+#             */
/*   Updated: 2025/02/03 13:33:59 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	strval(char **str)
{
	if (!str[0])
	{
		free_split(str);
		return (0);
	}
	return (1);
}

void	everythinghelp(int pos, int size, t_stack **b, t_stack **a)
{
	int	i;

	if (pos <= size / 2)
	{
		i = 0;
		while (i < pos)
		{
			rb(b);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < size - pos)
		{
			rrb(b);
			i++;
		}
	}
	pa(a, b);
}

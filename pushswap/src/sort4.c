/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 00:15:00 by rammisse          #+#    #+#             */
/*   Updated: 2025/02/03 13:33:27 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	chunksize(int size)
{
	if (size <= 100)
		return (16);
	else
		return (34);
}

int	findmax(t_stack *b)
{
	int		max;
	int		pos;
	int		currpos;
	t_stack	*current;

	max = b->index;
	pos = 0;
	currpos = 0;
	current = b;
	while (current)
	{
		if (current->index > max)
		{
			max = current->index;
			pos = currpos;
		}
		current = current->next;
		currpos++;
	}
	return (pos);
}

void	pushtob(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*copy;
	int		j;

	i = 0;
	j = chunksize(ft_lstsize(*a));
	while (*a)
	{
		copy = *a;
		if (copy->index <= i)
		{
			pb(a, b);
			i++;
		}
		else if (copy->index <= i + j)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else
			ra(a);
	}
}

void	pushtoa(t_stack **a, t_stack **b)
{
	int	pos;
	int	size;

	while (*b)
	{
		pos = findmax(*b);
		size = ft_lstsize(*b);
		everythinghelp(pos, size, b, a);
	}
}

void	sorteverything(t_stack **a, t_stack **b)
{
	pushtob(a, b);
	pushtoa(a, b);
}

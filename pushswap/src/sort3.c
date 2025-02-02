/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:20:31 by rammisse          #+#    #+#             */
/*   Updated: 2025/01/31 01:42:18 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	helper(t_stack **a, t_stack **b)
{
	if ((*a) && (*a)->index == 0)
		pb(a, b);
	else if ((*a)->next && (*a)->next->index == 0)
	{
		sa(a);
		pb(a, b);
	}
	else if ((*a)->next->next && (*a)->next->next->index == 0)
	{
		ra(a);
		ra(a);
		pb(a, b);
	}
}

void	helpsort(t_stack **a, t_stack **b)
{
	helper(a, b);
	if ((*a)->next->next->next && (*a)->next->next->next->index == 0)
	{
		rra(a);
		rra(a);
		pb(a, b);
	}
	else if ((*a)->next->next->next->next
		&& (*a)->next->next->next->next->index == 0)
	{
		rra(a);
		pb(a, b);
	}
}

void	tosort(t_stack **a, t_stack **b)
{
	if ((*a) && (*a)->index == 1)
		pb(a, b);
	else if ((*a)->next && (*a)->next->index == 1)
	{
		sa(a);
		pb(a, b);
	}
	else if ((*a)->next->next && (*a)->next->next->index == 1)
	{
		ra(a);
		ra(a);
		pb(a, b);
	}
	else if ((*a)->next->next->next && (*a)->next->next->next->index == 1)
	{
		rra(a);
		pb(a, b);
	}
	else if ((*a)->next->next->next->next
		&& (*a)->next->next->next->next->index == 1)
	{
		rra(a);
		pb(a, b);
	}
}

void	sort5(t_stack **a, t_stack **b)
{
	helpsort(a, b);
	tosort(a, b);
	sort3(a);
	pa(a, b);
	pa(a, b);
}

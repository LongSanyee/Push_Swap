/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:46:57 by rammisse          #+#    #+#             */
/*   Updated: 2025/02/02 11:53:46 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	issorted(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	while (current && current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

void	helpersort(t_stack **a, t_stack **b)
{
	if ((*a)->index == 0)
	{
		pb(a, b);
		sort3(a);
		pa(a, b);
	}
	else if ((*a)->next->index == 0)
	{
		sa(a);
		pb(a, b);
		sort3(a);
		pa(a, b);
	}
}

void	sort3(t_stack **a)
{
	if ((*a)->content > (*a)->next->content
		&& (*a)->content > (*a)->next->next->content)
		ra(a);
	else if ((*a)->next->content > (*a)->next->next->content)
		rra(a);
	if ((*a)->content > (*a)->next->content)
		sa(a);
}

void	sort4(t_stack **a, t_stack **b)
{
	assignindex(a);
	helpersort(a, b);
	if ((*a)->next->next->index == 0)
	{
		ra(a);
		ra(a);
		pb(a, b);
		sort3(a);
		pa(a, b);
	}
	else if ((*a)->next->next->next->index == 0)
	{
		rra(a);
		pb(a, b);
		sort3(a);
		pa(a, b);
	}
}

void	sortmini(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) == 2)
		sa(a);
	else if (ft_lstsize(*a) == 3)
		sort3(a);
	else if (ft_lstsize(*a) == 4)
		sort4(a, b);
	else if (ft_lstsize(*a) == 5)
		sort5(a, b);
}

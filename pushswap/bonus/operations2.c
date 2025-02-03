/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 04:22:28 by rammisse          #+#    #+#             */
/*   Updated: 2025/02/03 14:52:17 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

void	reverserotate(t_stack **a)
{
	t_stack	*secondtolast;
	t_stack	*last;

	secondtolast = *a;
	while (secondtolast->next->next)
		secondtolast = secondtolast->next;
	last = secondtolast->next;
	secondtolast->next = NULL;
	last->next = *a;
	*a = last;
}

void	rra(t_stack **a)
{
	reverserotate(a);
}

void	rrb(t_stack **b)
{
	reverserotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverserotate(a);
	reverserotate(b);
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
}

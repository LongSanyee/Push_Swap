/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 04:22:28 by rammisse          #+#    #+#             */
/*   Updated: 2025/01/31 01:34:44 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

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
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	reverserotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverserotate(a);
	reverserotate(b);
	write(1, "rrr\n", 4);
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

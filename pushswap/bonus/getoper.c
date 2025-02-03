/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getoper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:54:31 by rammisse          #+#    #+#             */
/*   Updated: 2025/02/03 17:43:44 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

void	freeevery(t_stack **a, t_stack **b, char *av)
{
	freealll(a);
	freealll(b);
	free(av);
	erro();
}

void	checkarg(char *av, t_stack **a, t_stack **b)
{
	if (ft_strncmp(av, "pa\n", 3) == 0)
		pa(a, b);
	else if (ft_strncmp(av, "pb\n", 3) == 0)
		pb(a, b);
	else if (ft_strncmp(av, "ra\n", 3) == 0)
		ra(a);
	else if (ft_strncmp(av, "rb\n", 3) == 0)
		rb(b);
	else if (ft_strncmp(av, "rra\n", 4) == 0)
		rra(a);
	else if (ft_strncmp(av, "rrb\n", 4) == 0)
		rrb(b);
	else if (ft_strncmp(av, "sa\n", 3) == 0)
		sa(a);
	else if (ft_strncmp(av, "sb\n", 3) == 0)
		sb(b);
	else if (ft_strncmp(av, "ss\n", 3) == 0)
		ss(a, b);
	else if (ft_strncmp(av, "rrr\n", 4) == 0)
		rrr(a, b);
	else if (ft_strncmp(av, "rr\n", 3) == 0)
		rr(a, b);
	else
		freeevery(a, b, av);
}

void	getnext(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		checkarg(line, a, b);
		free(line);
		line = get_next_line(0);
	}
}

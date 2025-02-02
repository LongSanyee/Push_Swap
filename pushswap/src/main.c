/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:10:43 by rammisse          #+#    #+#             */
/*   Updated: 2025/02/02 12:40:17 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	freealll(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

void	error(t_stack **a)
{
	freealll(a);
	erro();
}

int	checkduplicate(t_stack **stack)
{
	t_stack	*current;
	t_stack	*runner;

	current = *stack;
	while (current && current->next)
	{
		runner = current->next;
		while (runner)
		{
			if (current->content == runner->content)
				return (0);
			runner = runner->next;
		}
		current = current->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = NULL;
	if (ac < 2)
		return (0);
	parseargs(&a, ac, av);
	assignindex(&a);
	if (!checkduplicate(&a))
		error(&a);
	else if (ft_lstsize(a) < 6 && !issorted(&a))
		sortmini(&a, &b);
	else if (ft_lstsize(a) > 6 && !issorted(&a))
		sorteverything(&a, &b);
	freealll(&a);
	freealll(&b);
	return (0);
}

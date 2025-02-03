/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:15:25 by rammisse          #+#    #+#             */
/*   Updated: 2025/02/03 20:50:38 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

int	is_valid_number(char *token)
{
	int	i;

	i = 0;
	if (token[i] == '+' || token[i] == '-')
		i++;
	if (token[i] == '\0')
		return (0);
	while (token[i])
	{
		if (!ft_isdigit(token[i]))
			return (0);
		i++;
	}
	return (1);
}

int	isvalid(char **av)
{
	int		j;
	char	**temp;
	int		k;

	j = 1;
	while (av[j])
	{
		temp = ft_split(av[j], ' ');
		if (!temp || !strval(temp))
			return (0);
		k = 0;
		while (temp[k])
		{
			if (!is_valid_number(temp[k]))
			{
				free_split(temp);
				return (0);
			}
			k++;
		}
		free_split(temp);
		j++;
	}
	return (1);
}

void	check(char **av)
{
	if (isvalid(av) == 0)
		erro();
}

void	checkoverflow(t_stack **stack, char **temp, long value)
{
	if (value > INT_MAX || value < INT_MIN)
	{
		free_split(temp);
		freealll(stack);
		erro();
	}
}

void	parseargs(t_stack **stack, int ac, char **av)
{
	int		i;
	int		j;
	long	value;
	t_stack	*node;
	char	**temp;

	i = 1;
	check(av);
	while (i < ac)
	{
		temp = ft_split(av[i++], ' ');
		if (!temp)
			return ;
		j = 0;
		while (temp[j])
		{
			value = ft_atoi(temp[j++]);
			checkoverflow(stack, temp, value);
			node = ft_lstnew(value);
			if (!node)
				return ;
			ft_lstadd_back(stack, node);
		}
		free_split(temp);
	}
}

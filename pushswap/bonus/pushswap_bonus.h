/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:01:29 by rammisse          #+#    #+#             */
/*   Updated: 2025/02/03 20:49:34 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_BONUS_H
# define PUSHSWAP_BONUS_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "./get_next_line_bonus/get_next_line.h"

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;

}	t_stack;

int		main(int ac, char **av);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
long	ft_atoi(char *str);
char	**ft_split(char const *s, char c);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	freealll(t_stack **stack);
void	erro(void);
void	pa(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	pb(t_stack **a, t_stack **b);
void	sb(t_stack **b);
void	rb(t_stack **b);
void	ra(t_stack **a);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	push(t_stack **src, t_stack **dest);
int		issorted(t_stack **stack);
int		ft_isdigit(int c);
int		isvalid(char **av);
void	free_split(char **arr);
int		strval(char **str);
t_stack	*ft_lstnew(int cntnt);
void	parseargs(t_stack **stack, int ac, char **av);
void	getnext(t_stack **a, t_stack **b);

#endif
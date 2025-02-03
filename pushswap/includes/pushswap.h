/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:10:58 by rammisse          #+#    #+#             */
/*   Updated: 2025/02/03 20:36:55 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;

}	t_stack;

int		main(int ac, char **av);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
long	ft_atoi(char *str);
char	**ft_split(char const *s, char c);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	pushtob(t_stack **a, t_stack **b);
void	sorteverything(t_stack **a, t_stack **b);
int		*copynode(t_stack **a);
void	assignindex(t_stack **a);
void	sort5(t_stack **a, t_stack **b);
void	helper(t_stack **a, t_stack **b);
void	helpsort(t_stack **a, t_stack **b);
void	sortarr(int *arr, int n);
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
void	sort3(t_stack **a);
void	sort4(t_stack **a, t_stack **b);
void	helpersort(t_stack **a, t_stack **b);
void	sortmini(t_stack **a, t_stack **b);
int		issorted(t_stack **stack);
int		ft_isdigit(int c);
int		isvalid(char **av);
void	free_split(char **arr);
int		strval(char **str);
void	everythinghelp(int pos, int size, t_stack **b, t_stack **a);
t_stack	*ft_lstnew(int cntnt);
void	parseargs(t_stack **stack, int ac, char **av);

#endif
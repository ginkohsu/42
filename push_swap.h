/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:26:47 by jinxu             #+#    #+#             */
/*   Updated: 2025/07/05 14:13:39 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

t_stack	*new_node(int val, int in);
t_stack	*last_node(t_stack *stk);
int		find_biggest(t_stack *stk);
void	stackadd_back(t_stack **stk, t_stack *new);
char	**parse_args(int argc, char **argv, int *size);
int		check_input(char **tmp, int size);
int		sorted(t_stack *stk);
t_stack	*init_list(char **tmp, int size);
void	set_index(t_stack *stack_a, int size);
void	sort_stack(t_stack **a, t_stack **b, int size);
void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rra(t_stack **a);
void	sa(t_stack **a);
void	push(t_stack **from, t_stack **to);
void	rotate(t_stack **stk);
void	swap(t_stack **stk);
void	rev_rotate(t_stack **stk);
void	ft_free(char **s);
long	ft_atol(const char *nptr);
void	free_stack(t_stack **stk);

#endif

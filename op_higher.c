/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_higher.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:50:36 by jinxu             #+#    #+#             */
/*   Updated: 2025/07/05 14:00:58 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rra(t_stack **a)
{
	rev_rotate(a);
	write (1, "rra\n", 4);
}

void	sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

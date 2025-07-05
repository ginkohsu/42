/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:39:52 by jinxu             #+#    #+#             */
/*   Updated: 2025/07/05 13:59:29 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **from, t_stack **to)
{
	t_stack	*tmp;

	if (!from || !*from)
		return ;
	tmp = *from;
	*from = tmp -> next;
	tmp -> next = *to;
	*to = tmp;
}

void	swap(t_stack **stk)
{
	t_stack	*head;
	t_stack	*second;

	if (!stk || !*stk || !((*stk)-> next))
		return ;
	head = *stk;
	second = head -> next;
	head -> next = second -> next;
	second -> next = head;
	*stk = second;
}

void	rotate(t_stack **stk)
{
	t_stack	*head;
	t_stack	*last;

	if (!stk || !*stk || !((*stk)-> next))
		return ;
	head = *stk;
	*stk = head -> next;
	last = last_node(*stk);
	head -> next = NULL;
	last -> next = head;
}

void	rev_rotate(t_stack	**stk)
{
	t_stack	*prev;
	t_stack	*last;

	if (!stk || !*stk || !((*stk)-> next))
		return ;
	last = *stk;
	while (last -> next)
	{
		prev = last;
		last = last -> next;
	}
	last -> next = *stk;
	*stk = last;
	prev -> next = NULL;
}

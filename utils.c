/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:39:52 by jinxu             #+#    #+#             */
/*   Updated: 2025/07/05 14:11:04 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int val, int in)
{
	t_stack	*node;

	node = (t_stack *) malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node -> value = val;
	node -> index = in;
	node -> next = NULL;
	return (node);
}

t_stack	*last_node(t_stack *stk)
{
	while (stk -> next)
		stk = stk -> next;
	return (stk);
}

void	stackadd_back(t_stack **stk, t_stack *new)
{
	t_stack	*stk_node;

	if (!stk || !new)
		return ;
	if (*stk == NULL)
	{
		*stk = new;
		return ;
	}
	stk_node = last_node(*stk);
	stk_node -> next = new;
}

int	find_biggest(t_stack *stk)
{
	int		big;
	t_stack	*tmp;

	big = INT_MIN;
	tmp = stk;
	while (tmp)
	{
		if (tmp -> index > big)
			big = tmp -> index;
		tmp = tmp -> next;
	}
	return (big);
}

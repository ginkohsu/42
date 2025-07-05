/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 22:06:10 by jinxu             #+#    #+#             */
/*   Updated: 2025/07/05 13:32:36 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_list(char **tmp, int size)
{
	int		i;
	t_stack	*lst;
	t_stack	*new;

	lst = NULL;
	i = 0;
	while (i < size)
	{
		new = new_node(ft_atoi(tmp[i]), -1);
		stackadd_back(&lst, new);
		i++;
	}
	return (lst);
}

void	set_index(t_stack *stack_a, int size)
{
	t_stack	*biggest;
	t_stack	*head;

	head = stack_a;
	while (size > 0)
	{
		biggest = NULL;
		stack_a = head;
		while (stack_a)
		{
			if ((stack_a -> index) < 0)
			{
				if (biggest == NULL || stack_a -> value > biggest -> value)
					biggest = stack_a;
			}
			stack_a = stack_a -> next;
		}
		if (biggest)
			biggest -> index = size - 1;
		size--;
	}
}

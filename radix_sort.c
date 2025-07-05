/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:50:36 by jinxu             #+#    #+#             */
/*   Updated: 2025/07/05 14:04:33 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_bits(t_stack *a)
{
	int	count;
	int	tmp;
	int	biggest;

	biggest = 0;
	while (a)
	{
		count = 1;
		tmp = a -> index;
		while (tmp >> 1)
		{
			count++;
			tmp = tmp >> 1;
		}
		if (count > biggest)
			biggest = count;
		a = a -> next;
	}
	return (biggest);
}

static void	sort_three(t_stack **stk)
{
	int	biggest;

	biggest = find_biggest(*stk);
	if ((*stk)-> index == biggest)
		ra(stk);
	else if ((*stk)-> next -> index == biggest)
		rra(stk);
	if ((*stk)-> index > (*stk)-> next -> index)
		sa(stk);
}

static void	sort_five(t_stack **a, t_stack **b, int size)
{
	while (size--)
	{
		if ((*a)-> index == 0 || (*a)-> index == 1)
			pb(a, b);
		else
			ra(a);
	}
	sort_three(a);
	pa(a, b);
	pa(a, b);
	if ((*a)-> index > (*a)-> next -> index)
		sa(a);
}

static void	radix_sort(t_stack **a, t_stack **b, int size)
{
	int	max_bits;
	int	i;
	int	j;

	max_bits = count_bits(*a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)-> index >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}

void	sort_stack(t_stack **a, t_stack **b, int size)
{
	if (size <= 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b, size);
	else
		radix_sort(a, b, size);
}

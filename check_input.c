/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:51:48 by jinxu             #+#    #+#             */
/*   Updated: 2025/07/05 13:27:37 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_duplicate(char **s, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (ft_strncmp(s[i], s[j], 11) == 0)
			return (1);
		j++;
	}
	return (0);
}

static int	check_integer(char *s)
{
	if (*s == '-' || *s == '+')
		s++;
	if (!*s)
		return (1);
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (1);
		s++;
	}
	return (0);
}

int	check_input(char **tmp, int size)
{
	int		i;
	long	val;

	i = 0;
	while (i < size)
	{
		if (check_integer(tmp[i]))
			return (2);
		val = ft_atol(tmp[i]);
		if (val > INT_MAX || val < INT_MIN)
			return (3);
		if (check_duplicate(tmp, i))
			return (4);
		i++;
	}
	return (0);
}

int	sorted(t_stack *stk)
{
	while (stk && stk -> next)
	{
		if (stk -> index > stk -> next -> index)
			return (0);
		stk = stk -> next;
	}
	return (1);
}

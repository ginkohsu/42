/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:19:20 by jinxu             #+#    #+#             */
/*   Updated: 2025/07/05 01:23:40 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**tmp;
	int		size;

	if (argc < 2)
		return (0);
	tmp = parse_args(argc, argv, &size);
	if (!tmp || check_input(tmp, size))
	{
		if (argc == 2)
			ft_free(tmp);
		return (write(2, "Error\n", 6), 1);
	}
	stack_a = init_list(tmp, size);
	if (argc == 2)
		ft_free(tmp);
	stack_b = NULL;
	set_index(stack_a, size);
	if (sorted(stack_a))
		return (free_stack(&stack_a), 0);
	sort_stack(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

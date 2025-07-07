/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:42:02 by jinxu             #+#    #+#             */
/*   Updated: 2025/07/07 15:24:11 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

char	**parse_args(int argc, char **argv, int *size)
{
	char	**tmp;

	if (argc == 2)
	{
		if (argv[1][0] == '\0')
			return (NULL);
		tmp = ft_split(argv[1], ' ');
		if (!tmp || tmp[0] == NULL)
		{
			ft_free(tmp);
			return (NULL);
		}
		*size = count_split(tmp);
	}
	else
	{
		tmp = argv + 1;
		*size = argc - 1;
	}
	return (tmp);
}

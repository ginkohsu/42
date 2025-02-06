/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:41:15 by jinxu             #+#    #+#             */
/*   Updated: 2025/02/05 20:41:22 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	size = max - min;
	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *)malloc (sizeof(int) * size);
	if (*range == NULL)
		return (-1);
	while (i < size)
		(*range)[i++] = min++;
	return (size);
}
//mistake:*range[i++] wihtout() it is going to the next array

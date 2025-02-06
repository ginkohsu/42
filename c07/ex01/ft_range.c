/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:42:01 by jinxu             #+#    #+#             */
/*   Updated: 2025/02/05 20:43:01 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;
	int	len;

	len = max - min;
	i = 0;
	if (min >= max)
		return (NULL);
	arr = (int *)malloc (sizeof(int) * len);
	if (arr != NULL)
	{
		while (min < max)
			arr[i++] = min++;
	}
	return (arr);
}

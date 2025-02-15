/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:19:35 by jinxu             #+#    #+#             */
/*   Updated: 2025/01/28 11:49:27 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb);

int	ft_sqrt(int nb)
{
	int	x;

	if (nb <= 0)
		return (0);
	x = 1;
	while (x <= nb)
	{
		if (x * x == nb)
			return (x);
		x++;
	}
	return (0);
}

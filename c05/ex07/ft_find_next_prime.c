/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:58:47 by jinxu             #+#    #+#             */
/*   Updated: 2025/01/27 12:28:12 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_is_prime(int nb)
{
	int	x;

	x = 2;
	while (x < nb)
	{
		if (nb % x == 0)
			return (0);
		x++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}

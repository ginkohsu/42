/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:39:56 by jinxu             #+#    #+#             */
/*   Updated: 2025/01/27 12:51:00 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb);

int	ft_iterative_factorial(int nb)
{
	int	i;

	if (nb < 0)
		return (0);
	else if (nb == 0 || nb == 1)
		return (1);
	else
		i = nb;
	while (i > 1)
	{
		nb = nb * (i - 1);
		i --;
	}
	return (nb);
}
/*
int main( )
{
	int nb = ft_iterative_factorial(4);
	printf("%d\n", nb);
}
*/

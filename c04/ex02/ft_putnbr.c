/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:30:42 by jinxu             #+#    #+#             */
/*   Updated: 2025/01/23 19:12:39 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	check_edge(int nb);

void	ft_putnbr(int nb)
{
	int		j;
	char	numstr[11];

	if (nb == -2147483648 || nb == 0)
	{	
		check_edge(nb);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	j = 0;
	while (nb != 0)
	{
		numstr[j] = (nb % 10) + '0';
		nb = nb / 10;
		j++;
	}
	while (j > 0)
	{
		write (1, &numstr[j - 1], 1);
		j --;
	}
}

void	check_edge(int nb)
{
	if (nb == -2147483648)
		write (1, "-2147483648", 11);
	else if (nb == 0)
		write(1, "0", 1);
}
/*
int	main(void)
{
	ft_putnbr(-4242420);
	return (0);
}
*/

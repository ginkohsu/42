/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:09:12 by jinxu             #+#    #+#             */
/*   Updated: 2025/02/03 21:31:18 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	while (*str)
	{	
		write(1, str, 1);
		str++;
	}
}

void	check_edge(int nb)
{
	if (nb == -2147483648)
		write (1, "-2147483648", 11);
	else if (nb == 0)
		write(1, "0", 1);
}

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

void	ft_show_tab(struct s_stock_str *par)
{
	while ((*par).str)
	{
		ft_putstr((*par).str);
		write(1, "\n", 1);
		ft_putnbr((*par).size);
		write(1, "\n", 1);
		ft_putstr((*par).copy);
		write(1, "\n", 1);
		par++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:12:43 by jinxu             #+#    #+#             */
/*   Updated: 2025/01/19 15:19:43 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a);
void	printr_mid(int x);
void	printr_top(int x);
void	printr_bot(int x);

void	printr_top(int x)
{
	int	c;

	c = 1;
	while (c <= x)
	{
		if (c == 1)
			ft_putchar('/');
		else if (c == x)
			ft_putchar('\\');
		else
			ft_putchar('*');
		c++;
	}
}

void	printr_bot(int x)
{
	int	c;

	c = 1;
	while (c <= x)
	{
		if (c == 1)
			ft_putchar('\\');
		else if (c == x)
			ft_putchar('/');
		else
			ft_putchar('*');
		c++;
	}
}

void	printr_mid(int x)
{
	int	c;

	c = 1;
	while (c <= x)
	{
		if (c == 1 || c == x)
			ft_putchar('*');
		else
			ft_putchar(' ');
		c++;
	}
}

void	rush(int x, int y)
{
	int	r;

	if ((x <= 0) || (y <= 0))
	{
		write(1, "error\n", 6);
		return ;
	}
	r = 1;
	while (r <= y)
	{
		if (r == 1)
			printr_top(x);
		else if (r == y)
			printr_bot(x);
		else
			printr_mid(x);
		ft_putchar('\n');
		r++;
	}
}

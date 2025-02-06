/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 09:48:49 by cwong             #+#    #+#             */
/*   Updated: 2025/01/18 09:49:34 by cwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	draw_rectangle(int x, int y)
{
	int	row;
	int	col;

	row = 1;
	col = 1;
	while (row <= y)
	{
		col = 1;
		while (col <= x)
		{
			if ((row == 1 || row == y) && (col == 1 || col == x))
				ft_putchar('o');
			else if ((row == 1 || row == y) && (col > 1 || col < x))
				ft_putchar('-');
			else if ((row != 1 && row != y) && (col == 1 || col == x))
				ft_putchar('|');
			else if ((row != 1 && row != y) && (col != 1 || col != x))
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}

void	rush(int x, int y)
{
	if ((x <= 0) || (y <= 0))
	{
		write(1, "error\n", 6);
		return ;
	}
	draw_rectangle(x, y);
}

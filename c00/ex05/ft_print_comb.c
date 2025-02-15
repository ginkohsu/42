/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:17:28 by jinxu             #+#    #+#             */
/*   Updated: 2025/01/16 16:07:46 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	c;
	char	b;
	char	a;

	c = '0';
	while (c <= '7')
	{
		b = c + 1;
		while (b <= '8')
		{
			a = b + 1;
			while (a <= '9')
			{
				write (1, &c, 1);
				write (1, &b, 1);
				write (1, &a, 1);
				if (!(c == '7' && b == '8' && a == '9'))
					write (1, ", ", 2);
				a++;
			}
			b++;
		}
		c++;
	}
}

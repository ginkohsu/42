/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:11:53 by jinxu             #+#    #+#             */
/*   Updated: 2025/01/19 12:30:57 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size);

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;	
	int	temp;

	i = 0;
	j = 0;
	if (size > 1)
	{
		j = 0;
		while (j < size - 3)
		{
			i = 0;
			while (i < (size - 1 - j))
			{	
				if (tab[i] > tab [i + 1])
				{	
					temp = tab[i];
					tab[i] = tab[i + 1];
					tab[i + 1] = temp;
				}
				i++;
			}
			j++;
		}	
	}
}

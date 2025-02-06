/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:11:53 by jinxu             #+#    #+#             */
/*   Updated: 2025/01/19 12:25:39 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_sort_int_tab(int *tab, int size);

int main ()
{
	int arr[6] = {15, 0, 100, -400, 70, 20};
	int i;

	ft_sort_int_tab(arr, 6);
	for(i = 0; i < 6; i++) {
		printf("%d ",  arr[i]);
	}
	return 0;
}

void ft_sort_int_tab(int *tab, int size)
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
			while (i < (size-1-j))
			{	if (tab[i] > tab [i+1])
				{	
					temp = tab[i];
					tab[i] = tab[i+1];
					tab[i+1] = temp;
				}
			i++;
			}
		j++;
		}	
	}
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ternary_callers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloimusa <aloimusa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:43:21 by aloimusa          #+#    #+#             */
/*   Updated: 2025/02/02 23:38:03 by aloimusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

char	*ft_buffer(char *str)
{
	char	*array;
	int		size;
	int		i;
	int		n;

	size = str_len(str);
	while (size % 3 != 0)
		size++;
	array = malloc((size + 1) * sizeof(char));
	if (!array)
		return (NULL);
	i = 0;
	while (i < size)
		array[i++] = '0';
	i = 0;
	n = 0;
	while (i < size)
		array[n++ + size - str_len(str)] = str[i++];
	array[++i] = '\0';
	return (array);
}

void	call_ternary(char *array)
{
	char	call_array[3];
	int		i[2];

	i[0] = 0;
	i[1] = str_len(array) / 3;
	while (i[1] > 0)
	{
		call_array[0] = array[i[0]++];
		call_array[1] = array[i[0]++];
		call_array[2] = array[i[0]++];
		if (call_array[0] > '0')
			call_num(call_array[0], hundreds);
		if (call_array[1] == '1' && call_array[2] != '0')
			call_num(call_array[1], teens);
		if (call_array[1] > '1' || (call_array[1] == '1'
				&& call_array[2] == '0'))
			call_num(call_array[1], tenz);
		if (call_array[2] > '0' && call_array[1] != '1')
			call_num(call_array[2], ones);
		if (call_array[0] > '0' || call_array[1] > '0' || call_array[2] > '0')
			call_num(i[1] - 1, npwthousands);
		i[1]--;
	}
}

void	call_num(char num, int name)
{
	char	*letter;

	if (name == ones || name == hundreds)
		letter = ones_str(num);
	if (name == teens)
		letter = teens_str(num);
	if (name == tenz)
		letter = tenz_str(num);
	if (name != npwthousands)
		printword(letter);
	if (name == hundreds)
	{
		letter = hun_str(num);
		printword(letter);
	}
	if (name == npwthousands)
	{
		letter = pow_str(num);
		if (letter[0] == '1')
			printword(letter);
		if (letter)
			free(letter);
	}
}

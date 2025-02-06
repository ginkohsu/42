/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloimusa <aloimusa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:51:35 by aloimusa          #+#    #+#             */
/*   Updated: 2025/02/02 20:51:37 by aloimusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

char	*pow_str(char num)
{
	int		length;
	char	*string;
	int		i;

	i = 0;
	length = 1;
	while (i < num)
	{
		length += 3;
		i++;
	}
	string = malloc(length * sizeof(char) + 1);
	if (!string)
		return (NULL);
	string[0] = '1';
	i = 1;
	while (i < length)
		string[i++] = '0';
	string[i] = '\0';
	if (num == 0)
		string[--i] = '\0';
	return (string);
}

char	*ones_str(char num)
{
	char	*string;

	string = malloc(2);
	string[0] = num;
	string[1] = '\0';
	return (string);
}

char	*teens_str(char num)
{
	char	*string;

	string = malloc(3);
	string[0] = '1';
	string[1] = num;
	string[2] = '\0';
	return (string);
}

char	*tenz_str(char num)
{
	char	*string;

	string = malloc(3);
	string[0] = num;
	string[1] = '0';
	string[2] = '\0';
	return (string);
}

char	*hun_str(char num)
{
	char	*string;

	(void)num;
	string = malloc(4);
	string[0] = '1';
	string[1] = '0';
	string[2] = '0';
	string[3] = '\0';
	return (string);
}

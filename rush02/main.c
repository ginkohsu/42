/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloimusa <aloimusa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 21:19:52 by aloimusa          #+#    #+#             */
/*   Updated: 2025/02/02 23:16:12 by aloimusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

static char	*g_dict;
/*global variable dict*/

void	initialize_dict(void)
{
	g_dict = read_file("numbers.dict");
	if (!g_dict)
		write(1, "Dict Error\n", 11);
}

void	printword(char *number_str)
{
	char	*word;

	word = search(g_dict, number_str);
	if (word)
	{
		ft_putstr(word);
	}
	else
		write (1, "Error\n", 6);
}

int	main(int argc, char **av)
{
	char	*array;

	if (argc == 2)
	{
		if (av_c(av[1]) == 1)
			return (1);
		if (av_toolong(av[1]) == 1)
			return (1);
		initialize_dict();
		if (!g_dict)
			return (1);
		if (zero_maker(av[1]) == 1)
		{
			free (g_dict);
			return (0);
		}
		array = ft_buffer(av[1]);
		call_ternary(array);
		activate();
		if (array)
			free (array);
		free (g_dict);
	}
	return (0);
}

int	av_c(char *str)
{
	if (something_wrong(str) == 1)
	{
		write (1, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	av_toolong(char *str)
{
	if (str_len(str) > 39)
	{
		write (1, "Dict Error\n", 11);
		return (1);
	}
	return (0);
}

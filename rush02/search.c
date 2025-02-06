/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloimusa <aloimusa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 21:19:37 by aloimusa          #+#    #+#             */
/*   Updated: 2025/02/02 21:19:40 by aloimusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

char	*search(char *dict, char *number_str)
{
	char	*line;
	char	*colon_pos;
	char	*number;
	char	*word;
	char	*duplicate;

	duplicate = ft_strdup(dict);
	ft_strtok_reset();
	line = ft_strtok(duplicate, '\n');
	while (line)
	{
		colon_pos = ft_strchr(line, ':');
		if (colon_pos)
		{
			*colon_pos = '\0';
			number = line;
			word = colon_pos + 1;
			if (ft_strcmp(number, number_str) == 0)
				return (word);
		}
		line = ft_strtok(NULL, '\n');
	}
	free(duplicate);
	write(1, "Dict Error\n", 11);
	return (NULL);
}

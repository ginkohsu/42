/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   something_wrong.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloimusa <aloimusa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:51:43 by aloimusa          #+#    #+#             */
/*   Updated: 2025/02/02 23:15:09 by aloimusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

int	something_wrong(char *arg)
{
	if (arg[0] == '0')
	{
		if (arg[1] == '\0')
			return (-1);
		return (1);
	}
	while (*arg != '\0')
	{
		if (*arg >= '0' && *arg <= '9')
			arg++;
		else
			return (1);
	}
	return (0);
}

int	zero_maker(char *arg)
{
	char	*zero;

	if (something_wrong(arg) == -1)
	{
		zero = malloc(2 * sizeof(char));
		zero[0] = '0';
		zero[1] = '\0';
		printword(zero);
		activate();
		free(zero);
		return (1);
	}
	(void) zero;
	return (0);
}

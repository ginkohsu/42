/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:21:06 by jinxu             #+#    #+#             */
/*   Updated: 2025/02/02 23:16:46 by aloimusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

static char		*g_strings[100];
static int		g_count = 0;

void	ft_putstr(char *str)
{
	if (*str == ' ')
		str++;
	if (g_count < 100)
		g_strings[g_count++] = str;
}

void	activate(void)
{
	int		i;
	char	*str;

	i = 0;
	while (i < g_count)
	{
		str = g_strings[i];
		if (i != 0 && str != NULL)
			write(1, " ", 1);
		while (*str)
			write(1, str++, 1);
		i++;
	}
	write(1, "\n", 1);
}

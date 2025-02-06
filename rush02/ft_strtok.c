/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 21:07:56 by jinxu             #+#    #+#             */
/*   Updated: 2025/02/02 21:18:53 by aloimusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <stdlib.h>

static char	*g_current_pos;

/*reset the tokenizer*/
void	ft_strtok_reset(void)
{
	g_current_pos = NULL;
}

char	*ft_strtok(char *str, char delim)
{
	char		*token_start;

	if (str != NULL)
		g_current_pos = str;
	while (*g_current_pos == delim)
		g_current_pos++;
	if (*g_current_pos == '\0')
		return (NULL);
	token_start = g_current_pos;
	while (*g_current_pos != '\0' && *g_current_pos != delim)
		g_current_pos++;
	if (*g_current_pos == delim)
	{
		*g_current_pos = '\0';
		g_current_pos++;
	}
	return (token_start);
}

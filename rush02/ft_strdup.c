/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloimusa <aloimusa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:49:47 by aloimusa          #+#    #+#             */
/*   Updated: 2025/02/02 19:29:29 by aloimusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

int		length(char *str);
void	ft_dupcpy(char *src, char *dest);

char	*ft_strdup(char *src)
{
	char	*duplicate;

	duplicate = (char *) malloc((length(src) + 1) * sizeof(char));
	if (!duplicate)
		return (NULL);
	ft_dupcpy(src, duplicate);
	return (duplicate);
}

int	length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_dupcpy(char *src, char *dest)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
}

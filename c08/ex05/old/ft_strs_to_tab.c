/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:34:04 by jinxu             #+#    #+#             */
/*   Updated: 2025/02/03 21:29:36 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*newstr;

	i = 0;
	newstr = (char *)malloc (sizeof(char) * ft_strlen(src) + 1);
	if (newstr != NULL)
	{
		while (*src)
			newstr[i++] = *src++;
		newstr[i] = '\0';
	}
	return (newstr);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*tab;
	int					i;

	tab = (struct s_stock_str *)malloc (sizeof(struct s_stock_str) * ac);
	if (! tab)
		return (NULL);
	i = 0;
	while (i < (ac - 1))
	{
		tab[i].size = ft_strlen(av[i + 1]);
		tab[i].str = av[i + 1];
		tab[i].copy = ft_strdup(av[i + 1]);
		i++;
	}
	tab[i].size = 1;
	tab[i].str = 0;
	tab[i].copy = 0;
	return (tab);
}

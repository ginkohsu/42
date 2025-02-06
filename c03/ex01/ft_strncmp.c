/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:28:35 by jinxu             #+#    #+#             */
/*   Updated: 2025/01/26 15:38:16 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main ( )
{
    char s1[] = "aaaa ";
    char s2[] = "aaaa";

    unsigned int n = 4;
    int cmp = ft_strncmp(s1, s2, n);
    int check = strncmp(s1, s2, n);
    printf("%d\n", cmp);
    printf("%d\n", check);
}
*/

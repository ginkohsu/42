/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:39:10 by jinxu             #+#    #+#             */
/*   Updated: 2025/01/28 18:19:33 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (*s++)
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
/*  
The  strdup()  function  returns a pointer to
a new string which is a duplicate of the string s.
Memory for the new string is obtained with malloc(3), 
and can be freed with free(3).

if (!(newstr = ...)): This checks if the malloc call failed,
meaning newstr will be NULL if memory allocation fails.
If this happens, the function will return NULL.*/

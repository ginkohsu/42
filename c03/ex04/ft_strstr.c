/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:48:10 by jinxu             #+#    #+#             */
/*   Updated: 2025/01/22 18:49:34 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> 

char	*ft_strstr(char *str, char *to_find);

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	if (*to_find == '\0')
		return (str);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{	
			k = i;
			while (to_find[j] != '\0' && str[i + j] == to_find[j])
			{
				j++;
			}	
			if (to_find[j] == '\0')
				return (&str[k]);
		}
		i++;
	}
	return (NULL);
}
/*
int main ( )
    {
    char *str = "hello world";
    char *substr = "ll";
    char *final =ft_strstr(str, substr);
    write (1, final, 9);
    }
*/

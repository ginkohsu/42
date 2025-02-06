/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:02:29 by jinxu             #+#    #+#             */
/*   Updated: 2025/01/22 18:43:53 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str);

char	*ft_strlowcase(char *str)
{
	char	*origin_str;

	origin_str = str;
	while (*str)
	{
		if ((*str >= 'A') && (*str <= 'Z'))
		{
			*str = *str - 'A' + 'a' ;
		}
		str++;
	}
	str = origin_str;
	return (str);
}

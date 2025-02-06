/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:02:29 by jinxu             #+#    #+#             */
/*   Updated: 2025/01/22 18:43:43 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str);

char	*ft_strupcase(char *str)
{
	char	*origin_str;

	origin_str = str;
	while (*str)
	{
		if ((*str >= 'a') && (*str <= 'z'))
		{
			*str = *str + 'A' - 'a' ;
		}
		str++;
	}
	str = origin_str;
	return (str);
}

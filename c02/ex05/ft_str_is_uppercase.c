/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:14:51 by jinxu             #+#    #+#             */
/*   Updated: 2025/01/22 18:43:18 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str);

int	ft_str_is_uppercase(char *str)
{
	while (*str)
	{
		if (*str < 'A' || *str > 'Z')
		{
			return (0);
		}
		str ++;
	}
	return (1);
}

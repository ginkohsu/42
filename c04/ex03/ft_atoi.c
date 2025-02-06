/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:50:06 by jinxu             #+#    #+#             */
/*   Updated: 2025/01/24 12:20:45 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	numbercount(char *str);

int	ft_atoi(char *str)
{
	int	c_minus;
	int	nb;

	c_minus = 0;
	nb = 0;
	while (*str == ' ' || *str == '\f'
		|| *str == '\n' || *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{	
			c_minus ++;
		}
		str++;
	}
	nb = numbercount(str);
	if (c_minus % 2 == 1)
	{
		nb = 0 - nb;
	}
	return (nb);
}

int	numbercount(char *str)
{
	int	nb;

	nb = 0;
	while (*str >= '0' && *str <= '9')
		{	
			nb = nb * 10 + (*str - '0');
			str++;
		}
	return (nb);
}

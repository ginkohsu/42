/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:37:08 by jinxu             #+#    #+#             */
/*   Updated: 2025/01/22 18:44:07 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str);

int	t_alnum(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	t_al(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (t_al(str[i]))
		{	
			if (i == 0 || !t_alnum(str[i - 1]))
			{
				if (str[i] >= 'a' && str[i] <= 'z')
				{
					str[i] -= 32;
				}
			}
			else if (str[i] >= 'A' && str[i] <= 'Z')
			{
				str[i] += 32;
			}
		}
		i++;
	}
	return (str);
}

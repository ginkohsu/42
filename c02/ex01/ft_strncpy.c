/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:40:21 by jinxu             #+#    #+#             */
/*   Updated: 2025/01/22 18:42:20 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n);

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char			*origina_dest;
	unsigned int	i;

	origina_dest = dest;
	i = 0;
	while (*src && i < n)
	{	
		*dest = *src;
		dest ++;
		src ++;
		i ++;
	}
	while (i < n)
	{
		*dest = '\0';
		dest ++;
		i ++;
	}
	return (origina_dest);
}

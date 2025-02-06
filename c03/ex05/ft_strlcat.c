/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:36:37 by jinxu             #+#    #+#             */
/*   Updated: 2025/01/23 20:16:34 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	j = 0;
	while (dest[j] != '\0')
	{	
		j++;
	}
	k = 0;
	while (src[k] != '\0')
	{
		k++;
	}
	if (j >= size)
		return (size + k);
	i = 0;
	while (src[i] != '\0' && i < (size - j - 1))
	{
		dest[j + i] = src[i];
		i ++;
	}
	dest[j + i] = '\0';
	return (j + k);
}

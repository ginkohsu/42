/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:40:23 by jinxu             #+#    #+#             */
/*   Updated: 2025/02/05 20:40:29 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		strslen(int size, char**strs, char *sep);
void	copy_str(char *result, int *k, char *str);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		j;
	int		k;
	int		len;
	char	*result;

	len = strslen(size, strs, sep);
	result = (char *)malloc (sizeof(char) * len + 1);
	if (result != NULL)
	{
		j = 0;
		k = 0;
		while (j < size)
		{
			copy_str(result, &k, strs[j]);
			if (j != size - 1)
				copy_str(result, &k, sep);
			j++;
		}
		result[k] = '\0';
	}
	return (result);
}

void	copy_str(char *result, int *k, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		result[(*k)++] = str[i++];
}

int	strslen(int size, char**strs, char *sep)
{
	int	i;
	int	j;
	int	k;
	int	len;

	len = 0;
	j = 0;
	while (j < size)
	{
		i = 0;
		while (strs[j][i++])
		{
			len++;
		}
		if (j != size - 1)
		{
			k = 0;
			while (sep[k++])
				len++;
		}
		j++;
	}
	return (len);
}
/*
mistake# line 27
cannot write  ->  result = "" 
otherwise if (size == 0) then
we will try to allocate dynamic memory 
to a static one
mistake# dont forget null terminator after concatenation
mistake# should use index instead of *strs -segment error
*/

/* size == 0 edge case
Memory Allocation: malloc(sizeof(char)) allocates a single byte of memory, 
which is enough to store the null terminator ('\0').
What’s in result: After the allocation, result points to a memory location
that contains the null terminator ('\0'). This is a valid empty string in C.
Why Return It: You return this pointer (result),
which now points to a valid (albeit empty) string. 
This can be used in future code and freed later.
*/

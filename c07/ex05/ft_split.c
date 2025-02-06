/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 21:09:21 by jinxu             #+#    #+#             */
/*   Updated: 2025/02/06 13:27:01 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	is_delim(char c, char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

int	word_count(char *str, char *charset)
{
	int	count;
	int	in_word;

	in_word = 0;
	count = 0;
	while (*str)
	{
		if (is_delim(*str, charset))
			in_word = 0;
		else if (! in_word)
		{
			in_word = 1;
			count ++;
		}
		str++;
	}	
	return (count);
}

char	*extract_word(char **str, char *charset)
{
	char	*start;
	int		len;
	char	*substr;

	while (**str && is_delim(**str, charset))
		(*str)++;
	if (!**str)
		return (NULL);
	start = *str;
	len = 0;
	while (**str && !is_delim(**str, charset))
	{
		(*str)++;
		len++;
	}
	substr = (char *)malloc (len + 1);
	if (!substr)
		return (NULL);
	substr[len] = '\0';
	while (len)
	{
		len --;
		substr[len] = start[len];
	}
	return (substr);
}

char	**ft_split(char *str, char *charset)
{
	char	**lst;
	int		nb;
	int		i;

	if (!str || !*str)
		return (NULL);
	nb = word_count(str, charset);
	if (nb == 0)
		return (NULL);
	lst = malloc (sizeof(char *) * (nb + 1));
	if (!lst)
		return (NULL);
	i = 0;
	while (i < nb)
	{
		lst[i] = extract_word(&str, charset);
		if (!lst[i])
			return (NULL);
		i++;
	}
	lst[i] = 0;
	return (lst);
}

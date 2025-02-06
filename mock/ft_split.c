/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 21:09:21 by jinxu             #+#    #+#             */
/*   Updated: 2025/02/05 16:19:54 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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


int word_count(const char *s, char c)
{
	int i;
	int	count;
	
	count = 0;
	i = 0;
	while(s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c && (s[i+1] == c || s[i+1] == '\0'))
			count++;		
		i++;
	}
	return (count);
   
}

char *ft_substr(const char *start, int len)
{
	char	*substr;

	substr = (char *)malloc (sizeof(char) *(len + 1));
	if (!substr)
		return(NULL);
	char *substr = ft_strncpy(substr, start, len);
	substr[len] = '\0';
	return(substr);
}

void ft_free( char **arr)
{
	int	i;
	
	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{	free (arr[i]);
		i++;
	}
	free (arr);
}


char **ft_split(const char *s, char c)
{
	char		**lst;
	const char	*start;
	int			nb;
	int			i;

	if(!*s)
		return (NULL);
	nb = word_count(s, c);
	lst = malloc (sizeof(char *) * (nb + 1));
	if (!lst)
		return (NULL);
	
	i = 0;
	while ( i < nb)
	{
		while(*s == c)
		{
			s++;
		}
		start = s;
		len = 0;
		while ((*s != c) && (*s != '\0'))
		{
			s++;
			len++;
		}
		lst[i] = ft_substr(start, len);
		if (!lst[i])
		{
			ft_free(lst);
			return (NULL);
		}
		i++;
	}
	lst[i] = 0;
	return (lst);
}




























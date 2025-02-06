/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:58:42 by jinxu             #+#    #+#             */
/*   Updated: 2025/01/27 18:12:51 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	print_params(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			write (1, &argv[i][j], 1);
			j++;
		}
		write (1, "\n", 1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	while (i < (argc - 1))
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
			{	
				temp = argv[i];
				argv[i] = argv[j];
				argv[j] = temp;
			}
			j++;
		}
		i++;
	}
	print_params(argc, argv);
	return (0);
}
/*Strings in char **argv (or any char *array[])
are stored as pointers to their first characters.
Swapping two strings means swapping their pointers.
!!!!In C, everything is passed by value. This includes pointers.
When we pass a pointer to a (sub)function, we are passing a copy of the pointer,
not the original pointer itself.!!!
wrong example:
void swap(char *s1, char *s2)
{
    char *temp;

    temp = s1;  // we only changed
    s1 = s2;    // the local copies of s1 and s2
    s2 = temp;  // 
}
To actually modify the original pointers in the array,
we  need to pass pointers to pointers to the swap function.*/

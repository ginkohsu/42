#include <unistd.h>

int	ft_in_string(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	ft_already_printed(char c, char *str, int pos)
{
	int	i = 0;
	while (i < pos)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		i = 0;
	char	*s1;
	char	*s2;

	if (ac == 3)
	{
		s1 = av[1];
		s2 = av[2];
		while (s1[i])
		{
			if (ft_in_string(s1[i], s2) && !ft_already_printed(s1[i], s1, i))
				write(1, &s1[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}


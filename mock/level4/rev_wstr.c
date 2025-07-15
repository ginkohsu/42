#include  <unistd.h>

int	main(int ac,  char **av)
{
	char	*str;
	int		i;
	int		end;
	int		start;

	if (ac != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	str  = av[1];
	i = 0;
	while(str[i])
		i++;
	i--;
	while (i >= 0)
	{
		while (str[i] && str[i] != ' ' && str[i] != '\t')
			i--;
		i++;
		start = i;
		while (str[i] && str[i] != ' ' && str[i] != '\t')
			i++;
		i--;
		end = i;
		write (1, &(str[start]), end - start + 1);
		if (start != 0) // dangerous to  write str[start - 1]
			write (1, " ", 1);
		i =  start - 2;
	}
	return 0;
}


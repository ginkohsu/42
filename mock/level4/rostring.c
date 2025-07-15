#include <unistd.h>

int	main(int ac, char **av)
{
	char	*str = av[1];
	int		i;
	int		start;
	int		end_;
	int		j;

	if (ac < 2)
	{
		write (1, "\n", 1);
		return 0;
	}
	i  = 0;
	while (str[i] == ' ' || str[i]  ==  '\t')
		i++;
	start = i;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	end_= i;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i])
		{
			j = i;
			while (str[j] && str[j] != ' ' && str[j] != '\t')
				j++;
			
			write(1, &str[i], j - i);
			write(1," ", 1);
			i = j;
			while (str[i] == ' ' || str[i] == '\t')
       			 i++;
		}
	write (1, &str[start], end_-start);
	write (1,  "\n", 1);
	return 0;
}

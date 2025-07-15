#include <unistd.h>

int	ft_atoi(char *s)
{
	int	tmp;
	int	num = 0;

	while (*s)
	{
		tmp = *s - '0';
		num = num * 10 + tmp;
		s++;
	}
	return (num);
}

void	display_base16(int num)
{
	char *base = "0123456789abcdef";
	if (num >= 16) 
	{
		display_base16(num/16);
	}
	write (1, &base[num%16], 1);
}

int	main(int ac, char **av)
{
	char	*s;
	int		num;
	if (ac == 2)
	{
		s = av[1];
		num = ft_atoi(s);
		display_base16(num);
	}
	write (1, "\n", 1);
}

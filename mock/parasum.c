#include <unistd.h>

void ft_putnbr(int nbr)
{
	char arr[11];
	int x;
	int i;

	i = 0;
	while (nbr != 0)
	{
		x = nbr % 10;
		nbr = nbr / 10;
		arr[i] = x + '0';
		i++;
	}
	i--;
	while ( i >= 0)
	{
		write(1, &arr[i], 1);
		i --;
	}
}

int main (int ac, char**av)
{
	(void) av;

	ft_putnbr(ac - 1);
	write (1, "\n", 1);
	return (0);
}

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	num;
	int	i;

	i = 2;
	if (ac ==  2)
	{
		num = atoi(av[1]);
		if (num == 1) ;
			printf("1");
		while (i  <= num) //here  I need to learn it!!
		{
			if (num %  i  == 0)
			{
				printf("%d", i);
				if (num != i) //check not the last factor
					printf("*");
				num = num / i;
			}
			else
				i++;
		}
	}
	printf("\n");
	return (0);
}

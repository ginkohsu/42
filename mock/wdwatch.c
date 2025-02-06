#include <unistd.h>

int main(int ac, char **av)
{
	if (ac == 3)
	{
		char *s1 = av[1];
		char *s2 = av[2];
		int len;
		int i;

		len = 0;
		while(s1[len])
			len ++;

		i = 0;
		while ( i < len && *s2)/////
		{
			if(s1[i] == *s2)
			{
				i++;
			}
			s2++;/// same as   if (s1[i] == *s2++)     i++;//
		}1
		if (i == len)
			write (1, s1, len);
	}	
	write (1. "\n", 1);
	return (0);
}


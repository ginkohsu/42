#include <stdio.h>
#include "ft_abs.h"

int main (void)
{
	int nb;
	int a;
	int b;

	a = 40;
	b = 60;

	nb = a - b;
	nb = ABS(nb);
	printf("%d\n", nb);
	return (0);
}

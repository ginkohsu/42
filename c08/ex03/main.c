#include "ft_point.h"
#include <stdio.h>

void	set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}

int	main(void)
{
	t_point point;
	set_point(&point);
	printf("%d\n", point.x);
	printf("%d\n",point.y);
	return (0);
}


/*dereference with ->
use the pointer to
access members of a structure 

when we write:

p->x = 42;
p->y = 21;

What actually happens is:

(*p).x = 42;
(*p).y = 21;

*/

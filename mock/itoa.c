#include <stdlib.h>

char *ft_itoa(int n)
{
	char *str;
	int	len;
	int k;
	int neg;

	neg = 0;
	if ( n == -2147483648)
		return ("-2147483648");
	if ( n == 0)
		return ("0");
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	len = 0;
	k = n;
	while( k > 0)
	{
		k = k / 10;
		len ++;
	}

	str = malloc (sizeof(char) * (len + 1 + neg));
	if (!str)
		return (NULL);
	if(neg)
		str[0] = '-';
	str[len + neg] = '\0';

	while (len > 0)
	{
		str[len - 1 + neg] = n % 10 + '0';
		n = n/10;
		len --;
	}
	return (str);
}



int	ft_atoi_base(const char *str, int str_base)
{
	int		sign = 1;
	int		result = 0;
	int		tmp;
	char	c; //we can't change *str directly, because str is const char *.

	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		c = *str;
		if (c >= 'A' && c <= 'Z')
			c = c - 'A' + 'a';
		if (c >= '0' && c <= '9')
			tmp = c - '0';
		else if (c >= 'a' && c <='f')
			tmp = c - 'a' + 10;
		else
			break; //if c is not any of these then break;
		if (tmp >= str_base)
			break;
		result = result * str_base + tmp; //not result*10!!
		str++;
	}
	result = result * sign;
	return (result);
}

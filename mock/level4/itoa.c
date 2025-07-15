#include <stdlib.h>

/*
** 将一个整数转换为字符串，返回一个新分配的字符串指针
*/
char	*ft_itoa(int nbr)
{
	long	n = (long)nbr;  // 先将 int 转为 long，避免处理 INT_MIN 时溢出
	int		len = (n <= 0); // 如果是负数或 0，至少需要一个字符（'-' 或 '0'）
	long	tmp = n;        // 用临时变量 tmp 来计算长度
	char	*str;

	// 计算数字的长度（多少位数）
	while (tmp)
	{
		tmp /= 10;
		len++;
	}

	// 分配内存（长度 +1 是为了 '\0' 结尾符）
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0'; // 字符串结尾

	// 特殊情况：0 直接处理
	if (n == 0)
		str[0] = '0';
	// 如果是负数，先放置 '-'，再取绝对值
	else if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}

	// 从末尾开始填入每一位数字
	while (n > 0)
	{
		str[--len] = (n % 10) + '0'; // 模 10 得到当前最低位，加上 '0' 得到字符
		n /= 10;                     // 去掉最低位，继续下一位
	}

	return (str);
}


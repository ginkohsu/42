#include <stdlib.h>

int	word_count(const char *s, char c)
{
	int	i = 0;
	int	count = 0;

	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

// 从原字符串中复制 len 个字符形成新字符串（带 \0）
char	*ft_substr(const char *start, int len)
{
	char	*substr;
	int		i = 0;

	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (i < len)
	{
		substr[i] = start[i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

// 释放二维数组（ft_split 出错时调用）
void	ft_free(char **arr)
{
	int	i = 0;

	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

// 主函数：将字符串按分隔符 c 切成单词数组
// 返回值是一个 NULL 结尾的字符串数组
char	**ft_split(const char *s, char c)
{
	char		**lst;
	const char	*start;
	int			nb;
	int			len;
	int			i;

	if (!s)
		return (NULL);
	nb = word_count(s, c);
	lst = (char **)malloc(sizeof(char *) * (nb + 1));
	if (!lst)
		return (NULL);

	i = 0;
	while (i < nb)
	{
		// 跳过连续的分隔符
		while (*s == c)
			s++;

		// 标记单词起始位置
		start = s;
		len = 0;

		// 计算单词长度
		while (*s && *s != c)
		{
			s++;
			len++;
		}

		// 创建当前单词的副本
		lst[i] = ft_substr(start, len);
		if (!lst[i])
		{
			ft_free(lst);
			return (NULL);
		}
		i++;
	}
	lst[i] = NULL;  // 最后以 NULL 结尾
	return (lst);
}


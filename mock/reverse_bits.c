unsigned char	reverse_bits(unsigned char octet)
{
	int				i = 8;
	unsigned char	result = 0;

	while (i--)
	{
		result = (result << 1) | (octet & 1); // 将当前最低位加到result末尾
		octet >>= 1; // 右移继续提取下一位
	}
	return (result);
}


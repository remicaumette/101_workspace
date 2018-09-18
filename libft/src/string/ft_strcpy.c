char	*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (*src)
		dst[i++] = *src++;
	dst[i] = 0;
	return (dst);
}
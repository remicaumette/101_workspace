int	ft_tolower(int c)
{
	return ((c >= 'A' && c <= 'Z') ? (c - 'A' + 'a') : c);
}
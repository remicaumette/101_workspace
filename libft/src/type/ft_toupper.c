int	ft_toupper(int c)
{
	return ((c >= 'a' && c <= 'z') ? (c - 'a' + 'A') : c);
}
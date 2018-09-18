#include "ft_string.h"

static int	is_whitespace(char c)
{
	return c == ' ' || c == '\t' || c == '\n';
}

char		*ft_strtrim(char const *s)
{
	int	offset;
	int	limit;

	offset = 0;
	limit = ft_strlen(s);
	while (s[offset] && is_whitespace(s[offset]))
		offset++;
	while (limit - 1 > 0 && is_whitespace(s[limit - 1]))
		limit--;
	return (ft_strsub(s, offset, limit - offset));
}
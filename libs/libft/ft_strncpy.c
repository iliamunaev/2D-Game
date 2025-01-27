
/*
** Copies 'n' characters from 'src' to 'dest'.
** 'dest' must be large enough to hold the copied characters.
*/
#include "libft.h"

void	ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src && src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}
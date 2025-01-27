#include "libft.h"

/*
** Copies the string 'src' to 'dest'.
** Assumes 'dest' is large enough to hold 'src'.
*/

void	ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}
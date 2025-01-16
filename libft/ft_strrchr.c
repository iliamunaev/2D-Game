/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:39:48 by imunaev-          #+#    #+#             */
/*   Updated: 2024/11/07 08:39:49 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** strrchr() function locates the last occurrence of 'c'
** in the string pointed to by 's'. The terminating NUL character is
** considered to be part of the string.
** Return: a pointer to the byte, else null pointer.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*tail;
	size_t		s_len;

	s_len = ft_strlen(s);
	tail = s + s_len;
	if (!(char)c)
		return ((char *)tail);
	while (tail != s)
	{
		tail--;
		if (*tail == (char)c)
			return ((char *)tail);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:39:48 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/18 12:47:41 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the last occurrence of a character in a string.
 *
 * This function searches for the last occurrence of the character `c` in the
 * null-terminated string `s`. The null terminator (`\0`) is considered part
 * of the string, so `c` can be `\0` to locate the end of the string.
 *
 * @param s The string to search in.
 * @param c The character to locate, passed as an `int` but interpreted
 *          as `char`.
 * @return char* A pointer to the last occurrence of the character `c`
 *         in the string `s`, or NULL if the character is not found.
 */
char	*ft_strrchr(const char *s, int c)
{
	const char	*tail;
	size_t		len;

	len = ft_strlen(s);
	tail = s + len;
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

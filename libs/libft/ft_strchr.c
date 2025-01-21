/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:39:36 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/18 12:38:55 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the first occurrence of a character in a string.
 *
 * This function searches for the first occurrence of the character `c`
 * in the string `s`. The null-terminator character `\0` is considered part
 * of the string, so `c` can also be `\0` to locate the end of the string.
 *
 * @param s The string to search in.
 * @param c The character to locate, passed as an `int` but interpreted
 *          as `char`.
 * @return char* A pointer to the first occurrence of the character `c`
 *         in the string `s`, or NULL if the character is not found.
 */
char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (!(char)c)
		return ((char *)s);
	return (NULL);
}

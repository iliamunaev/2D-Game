/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:03:27 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/30 23:05:53 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies up to `n` characters from the source string
 * to the destination string.
 *
 * This function copies at most `n` characters from the source string `src` to
 * the destination buffer `dest`. If `src` is shorter than `n` characters,
 * `dest` is null-terminated. Unlike the standard `strncpy`, this implementation
 * explicitly null-terminates the destination string.
 *
 * @param dest The destination buffer where the string is copied.
 * @param src The source string to copy from.
 * @param n The maximum number of characters to copy.
 */
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

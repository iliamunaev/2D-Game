/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:45:14 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/18 12:31:39 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies a string to a destination buffer with size limitation.
 *
 * This function copies up to `size - 1` characters from the null-terminated
 * string `src` to the buffer `dest`, ensuring the result is null-terminated.
 * If `size` is 0, no characters are copied, but the function still returns
 * the length of `src`.
 *
 * @param dest The destination buffer where the string is copied.
 * @param src The source string to copy.
 * @param size The size of the destination buffer.
 * @return size_t The total length of the string `src`. This allows the caller
 *         to determine if the buffer was large enough to hold the entire string.
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (src_len);
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

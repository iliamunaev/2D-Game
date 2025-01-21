/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:14:26 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/18 12:37:17 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Appends a string to another, ensuring the result is null-terminated.
 *
 * This function appends the null-terminated string `src` to the end of `dest`.
 * It appends at most `size - strlen(dest) - 1` bytes and ensures the result
 * is null-terminated as long as `size` is greater than `strlen(dest)`.
 *
 * If the total length of `dest` and `src` exceeds `size`, the function
 * truncates the result and ensures null termination.
 *
 * @param dest The destination string to which `src` is appended.
 * @param src The source string to append.
 * @param size The total size of the destination buffer.
 * @return size_t The combined length of the strings `dest` and `src`
 *         (the length `src` would add to `dest` if there were no size
 *         restrictions).
 */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (len < size && dest[len])
		len++;
	i = 0;
	while ((len + i + 1) < size && src[i])
	{
		dest[len + i] = src[i];
		i++;
	}
	if (len < size)
		dest[len + i] = '\0';
	while (src[i])
		i++;
	return (len + i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:38:14 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/18 12:10:38 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Scans a memory area for a specific byte.
 *
 * This function searches the first `n` bytes of the memory area pointed to
 * by `s` for the first occurrence of the byte `c`. Both `c` and the bytes
 * in the memory area are treated as `unsigned char`.
 *
 * @param s The pointer to the memory area to be scanned.
 * @param c The byte to search for, interpreted as an `unsigned char`.
 * @param n The number of bytes to scan.
 * @return void* A pointer to the first occurrence of the byte `c` in the memory
 *         area, or NULL if `c` is not found within the first `n` bytes.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sptr;

	sptr = (unsigned char *)s;
	while (n > 0)
	{
		if (*sptr == (unsigned char)c)
			return ((void *)sptr);
		sptr++;
		n--;
	}
	return (NULL);
}

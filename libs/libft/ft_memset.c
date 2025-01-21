/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:39:13 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/18 12:35:23 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Fills a memory area with a specified byte.
 *
 * This function sets the first `n` bytes of the memory area pointed to
 * by `s` to the constant byte value `c`. It is commonly used to initialize
 * or reset memory to a specific value.
 *
 * @param s Pointer to the memory area to be filled.
 * @param c The byte value to set, passed as an `int` but cast to
 *          `unsigned char`.
 * @param n The number of bytes to fill.
 * @return void* A pointer to the memory area `s`.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*buffer;

	buffer = (unsigned char *)s;
	while (n > 0)
	{
		*buffer = (unsigned char)c;
		buffer++;
		n--;
	}
	return (s);
}

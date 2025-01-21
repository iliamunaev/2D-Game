/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 23:34:07 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/18 12:36:49 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compares two memory areas.
 *
 * This function compares the first `n` bytes of the memory areas
 * `s1` and `s2`. Each byte is interpreted as an `unsigned char`.
 *
 * @param s1 Pointer to the first memory area.
 * @param s2 Pointer to the second memory area.
 * @param n The number of bytes to compare.
 * @return int A value less than, equal to, or greater than zero:
 *         - Less than zero: The first differing byte in `s1` is less than
 *            the corresponding byte in `s2`.
 *         - Zero: The memory areas are identical for the first `n` bytes.
 *         - Greater than zero: The first differing byte in `s1` is greater
 *           than the corresponding byte in `s2`.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = (const unsigned char *)s1;
	ptr2 = (const unsigned char *)s2;
	while (n > 0)
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		ptr1++;
		ptr2++;
		n--;
	}
	return (0);
}

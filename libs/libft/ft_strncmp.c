/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:27:08 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/18 12:43:10 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compares two strings up to a specified number of bytes.
 *
 * This function compares the strings `s1` and `s2` up to at most `n` bytes
 * or until a null character is encountered in either string. The comparison
 * is performed lexicographically based on unsigned character values.
 *
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @param n The maximum number of bytes to compare.
 * @return int A value less than, equal to, or greater than zero:
 *         - Less than zero: `s1` is lexicographically less than `s2`.
 *         - Zero: `s1` and `s2` are equal for the first `n` bytes.
 *         - Greater than zero: `s1` is lexicographically greater than `s2`.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (*s1 != *s2 || *s1 == '\0' || *s2 == '\0')
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

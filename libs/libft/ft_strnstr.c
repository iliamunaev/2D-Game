/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 23:35:18 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/18 12:48:34 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates a substring within a string, searching up to
 *        a specified length.
 *
 * This function searches for the first occurrence of the null-terminated
 * string `little` within the string `big`, where no more than `len` characters
 * of `big` are examined. Characters after the `len` limit are not searched.
 *
 * @param big The string to be searched.
 * @param little The substring to locate.
 * @param len The maximum number of characters to search in `big`.
 * @return char* A pointer to the first occurrence of `little` in `big`
 *         if found:
 *         - If `little` is an empty string, the function returns `big`.
 *         - If `little` does not occur in the first `len` characters of `big`,
 *         the function returns NULL.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	j;
	size_t	i;

	if (*little == '\0')
		return ((char *)big);
	if (len == 0)
		return (0);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (i + j < len && big[i + j] == little[j])
		{
			if (little[j + 1] == '\0')
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (0);
}

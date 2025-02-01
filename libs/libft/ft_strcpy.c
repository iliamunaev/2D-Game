/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:06:26 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/30 23:06:57 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies a string from `src` to `dest`, including the null terminator.
 *
 * This function copies the string `src` into `dest`, character by character,
 * until it encounters the null terminator (`\0`). The destination string `dest`
 * must be large enough to hold the copied string, including the null terminator.
 *
 * @param dest The destination buffer where the string is copied.
 * @param src The source string to copy from.
 */
void	ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

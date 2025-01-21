/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:39:25 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/18 12:26:11 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Creates a duplicate of a string.
 *
 * This function allocates memory and returns a pointer to a new string
 * that is a duplicate of the string `s`. The memory for the new string
 * is obtained with `malloc` and can be freed with `free`.
 *
 * @param s The string to duplicate.
 * @return char* A pointer to the duplicated string, or NULL if insufficient
 *         memory was available. If NULL is returned, `errno` is set to indicate
 *         the error.
 */
char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*s_dup;

	len = ft_strlen(s);
	s_dup = malloc(len + 1);
	if (!s_dup)
		return (NULL);
	ft_strlcpy(s_dup, s, len + 1);
	return (s_dup);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:19:09 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/18 12:48:02 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Extracts a substring from a given string.
 *
 * This function allocates memory and returns a substring of the string `s`.
 * The substring starts at the index `start` and has a maximum length of `len`.
 * If `start` is greater than or equal to the length of `s`, the function
 * returns an empty string. If the requested `len` extends beyond the end of
 * the string, the function trims the length to fit the available characters.
 *
 * @param s The input string to extract the substring from. If NULL, the
 *          function returns NULL.
 * @param start The starting index of the substring.
 * @param len The maximum length of the substring.
 * @return char* A newly allocated substring, or NULL if memory
 *         allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		substr = malloc(1);
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (len > s_len - start)
		len = s_len - start;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:12:19 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/18 12:34:59 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Creates a new string by applying a function to each character
 * of a string.
 *
 * This function applies the given function `f` to each character of the
 * string `s`,
 * passing the character's index as the first argument and the character itself
 * as the second argument. The result of each function application is stored
 * in a * newly allocated string.
 *
 * @param s The string on which to iterate. If NULL, the function returns NULL.
 * @param f The function to apply to each character. It takes the character's
 *          index and the character itself as arguments.
 * @return char* A newly created string resulting from successive applications
 *         of `f`, or NULL if memory allocation fails or if `s` or `f` is NULL.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	unsigned int	i;
	unsigned int	len;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	if (!s || !f)
		return (NULL);
	new_str = malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	while (i < len)
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:01:47 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/18 20:58:46 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Splits a string into an array of substrings using a delimiter.
 *
 * This function allocates memory to create an array of substrings, splitting
 * the string `s` at every occurrence of the delimiter character `c`. The
 * resulting array is null-terminated. If memory allocation fails at any point,
 * previously allocated memory is freed.
 *
 * @param s The input string to be split. If NULL, the function returns NULL.
 * @param c The delimiter character used to split the string.
 * @return char** A pointer to the array of substrings resulting from the split.
 *         If memory allocation fails, the function returns NULL.
 */
static int	count_substr(char const *s, char delim)
{
	int	count;
	int	in_substr;

	count = 0;
	in_substr = 0;
	while (*s)
	{
		if (*s != delim && !in_substr)
		{
			in_substr = 1;
			count++;
		}
		else if (*s == delim)
			in_substr = 0;
		s++;
	}
	return (count);
}

static char	*create_substr(char const *start, int len)
{
	char	*substr;
	int		i;

	i = 0;
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (i < len)
	{
		substr[i] = start[i];
		i++;
	}
	substr[len] = '\0';
	return (substr);
}

static void	free_all_mem(char **arr, int i)
{
	while (i >= 0)
		free(arr[i--]);
	free(arr);
}

static int	fill_substrings(char **arr, char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		if (len > 0)
		{
			arr[i] = create_substr(s, len);
			if (!arr[i])
			{
				free_all_mem(arr, i - 1);
				return (0);
			}
			i++;
			s += len;
		}
	}
	arr[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		substr_count;

	if (!s)
		return (NULL);
	substr_count = count_substr(s, c);
	arr = malloc((substr_count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	if (!fill_substrings(arr, s, c))
		return (NULL);
	return (arr);
}

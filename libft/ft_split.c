/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:01:47 by imunaev-          #+#    #+#             */
/*   Updated: 2024/11/07 17:08:09 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns an array
** of strings obtained by splitting ’s’ using the
** character ’c’ as a delimiter. The array must end
** with a NULL pointer.
** s: The string to be split.
** c: The delimiter character.
** Return: The array of new strings resulting from the split.
** NULL if the allocation fails.
*/

#include "libft.h"

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

static void	free_all_mem(char **arr, int index)
{
	while (index >= 0)
		free(arr[index--]);
	free(arr);
}

static int	fill_substrings(char **arr, char const *s, char c)
{
	int	index;
	int	len;

	index = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		if (len > 0)
		{
			arr[index] = create_substr(s, len);
			if (!arr[index])
			{
				free_all_mem(arr, index - 1);
				return (0);
			}
			index++;
			s += len;
		}
	}
	arr[index] = NULL;
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

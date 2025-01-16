/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:30:55 by imunaev-          #+#    #+#             */
/*   Updated: 2024/11/07 15:30:58 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * The function allocates (with malloc(3)) and returns a copy of ’s1’
 * with the characters specified in ’set’ removed from the beginning
 * and the end of the string.
 * Return: the trimmed string, NULL if the allocation fails
 */

#include "libft.h"

static int	is_inset(char const *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str_trim;

	if (!s1)
		return (NULL);
	if (!set)
	{
		str_trim = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
		if (!str_trim)
			return (NULL);
		ft_strlcpy(str_trim, s1, ft_strlen(s1) + 1);
		return (str_trim);
	}
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && is_inset(set, s1[start]))
		start++;
	while (end > start && is_inset(set, s1[end - 1]))
		end--;
	str_trim = (char *)malloc((end - start + 1) * sizeof(char));
	if (!str_trim)
		return (NULL);
	ft_strlcpy(str_trim, s1 + start, end - start + 1);
	return (str_trim);
}

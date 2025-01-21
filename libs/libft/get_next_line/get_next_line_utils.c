/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:52:22 by imunaev-          #+#    #+#             */
/*   Updated: 2024/11/14 13:16:20 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Returns the length of the string 's'.
*/
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

/*
** Searches for the character 'c' in the string 's'.
** Returns a pointer to the first occurrence of 'c', or NULL if not found.
*/
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

/*
** Joins two strings 's1' and 's2' into a new string.
** Frees 's1' after joining.
** Returns the new string, or NULL if allocation fails.
*/
char	*ft_strjoin_and_free(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*new_str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_str = (char *)malloc(len1 + len2 + 1);
	if (!new_str)
	{
		free(s1);
		return (NULL);
	}
	ft_strcpy(new_str, s1);
	ft_strcpy(new_str + len1, s2);
	free(s1);
	return (new_str);
}

/*
** Copies 'n' characters from 'src' to 'dest'.
** 'dest' must be large enough to hold the copied characters.
*/
void	ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src && src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

/*
** Copies the string 'src' to 'dest'.
** Assumes 'dest' is large enough to hold 'src'.
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

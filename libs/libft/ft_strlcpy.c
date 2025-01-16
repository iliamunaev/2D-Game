/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:45:14 by imunaev-          #+#    #+#             */
/*   Updated: 2024/11/06 23:28:05 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_strlcpy copies up to 'size' - 1 characters from the NUL-terminated string
** 'src' to 'dest', NUL-terminating the result.
** Return: the total length of the created string (length of 'src').
*/

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (src_len);
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

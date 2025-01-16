/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:14:26 by imunaev-          #+#    #+#             */
/*   Updated: 2024/11/08 14:39:16 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_strlcat() appends the NUL-terminated string 'src' to the end of 'dest'.
** It will append at most size - strlen(dst) - 1 bytes,
** NUL-terminating the result.
** Return: the initial length of 'dest' plus the length of 'src'.
*/

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destl;
	size_t	i;

	destl = 0;
	while (destl < size && dest[destl])
		destl++;
	i = 0;
	while ((destl + i + 1) < size && src[i])
	{
		dest[destl + i] = src[i];
		i++;
	}
	if (destl < size)
		dest[destl + i] = '\0';
	while (src[i])
		i++;
	return (destl + i);
}

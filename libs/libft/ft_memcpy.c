/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:40:38 by imunaev-          #+#    #+#             */
/*   Updated: 2024/11/08 14:48:45 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_memcpy() copies 'n' bytes from memory area 'src' to memory area 'dest'.
** Return: a pointer to 'dest'.
*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	if (!dest && !src)
		return (malloc(0));
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

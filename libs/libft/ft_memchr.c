/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:38:14 by imunaev-          #+#    #+#             */
/*   Updated: 2024/11/07 11:52:15 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_memchr() scans the initial n bytes of the memory area pointed to by 's'
** for the first instance of 'c'. Both 'c' and the bytes of the memory
** area pointed to by 's' are interpreted as unsigned char.
** Return: a pointer to the matching byte;
** NULL if the character does not occur in the given memory area.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sptr;

	sptr = (unsigned char *)s;
	while (n--)
	{
		if (*sptr == (unsigned char)c)
			return ((void *)sptr);
		sptr++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:39:25 by imunaev-          #+#    #+#             */
/*   Updated: 2024/11/07 08:39:27 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_strdup() returns a pointer to a new string,
** which is a duplicate of the string pointed to by s.
** The returned pointer can be passed to free().
** Return: a pointer to the duplicated string;
** NULL if insufficient memory was available, with errno set to indicate
** the cause of the error.
*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	slen;
	char	*dupptr;

	slen = ft_strlen(s);
	dupptr = malloc(slen + 1);
	if (!dupptr)
		return (NULL);
	ft_strlcpy(dupptr, s, slen + 1);
	return (dupptr);
}

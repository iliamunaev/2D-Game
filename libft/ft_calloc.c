/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 23:38:01 by imunaev-          #+#    #+#             */
/*   Updated: 2024/11/08 14:40:12 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_calloc() allocates memory for an array of 'nmemb' elements of
** 'size' bytes each. The memory is set to zero.
** Return:  a pointer to the allocated memory;
** if 'nmemb' or 'size' is  0,  then  calloc()  returns  either NULL, or
** a unique pointer value that can later be successfully passed to free();
** if the multiplication of 'nmemb' and 'size' would result in integer overflow,
** then calloc() returns an error.
*/

#include "libft.h"

void	*ft_calloc(size_t element, size_t size)
{
	char	*res;
	size_t	n_bytes;

	n_bytes = size * element;
	if (size && element && (n_bytes % size || n_bytes % element))
		return (NULL);
	res = malloc(n_bytes);
	if (!res)
		return (NULL);
	ft_bzero(res, n_bytes);
	return ((void *)res);
}

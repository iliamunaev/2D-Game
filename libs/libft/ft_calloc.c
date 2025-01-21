/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 23:38:01 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/18 11:54:35 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates and initializes memory for an array.
 *
 * This function allocates memory for an array of `element` elements,
 * each of `size` bytes, and initializes all bytes in the allocated
 * memory to zero.
 *
 * @param element The number of elements to allocate.
 * @param size The size of each element in bytes.
 * @return void* A pointer to the allocated memory. Returns NULL if the
 *         allocation fails, if `element` or `size` is 0, or if the
 *         multiplication of `element` and `size` causes an integer overflow.
 */
void	*ft_calloc(size_t element, size_t size)
{
	char	*result;
	size_t	n_bytes;

	n_bytes = size * element;
	if (size && element && (n_bytes % size || n_bytes % element))
		return (NULL);
	result = malloc(n_bytes);
	if (!result)
		return (NULL);
	ft_bzero(result, n_bytes);
	return ((void *)result);
}

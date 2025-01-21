/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:37:46 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/18 11:54:51 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Erases data in a block of memory by setting it to zero.
 *
 * This function sets the first `n` bytes of the memory area
 * pointed to by `s` to zero bytes ('\0').
 *
 * @param s Pointer to the memory area to be zeroed.
 * @param n Number of bytes to set to zero.
 * @return void This function does not return a value.
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

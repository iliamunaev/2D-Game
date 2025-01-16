/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:37:46 by imunaev-          #+#    #+#             */
/*   Updated: 2024/11/07 08:37:50 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_bzero() erases the data in the n bytes of the memory starting
** at the location pointed to by s, by writing zeros (bytes containing '\0')
** to that area.
** Return Value: None.
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

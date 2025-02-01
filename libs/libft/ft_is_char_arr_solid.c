/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_char_arr_solid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:16:15 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/01 15:18:39 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if a string consists entirely of a specific character.
 *
 * This function iterates through a null-terminated string (`char *arr`)
 * and verifies whether all characters in the string are equal to `c`.
 *
 * @param arr A null-terminated string to check.
 * @param c The character to compare against each element in the string.
 * @return bool `true` if the entire string consists of only `c`, 
 * `false` otherwise.
 *         Undefined behaviour if `arr` is NULL.
 */
bool	ft_is_char_arr_solid(char *arr, char c)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] != c)
			return (false);
		i++;
	}
	return (true);
}

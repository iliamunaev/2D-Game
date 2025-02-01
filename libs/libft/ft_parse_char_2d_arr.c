/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_char_2d_arr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:48:05 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/01 14:51:57 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Counts occurrences of a character in a 2D array of strings.
 *
 * This function iterates through a NULL-terminated 2D array (`char **arr`)
 * and counts the total occurrences of a specified character `c` in all strings.
 *
 * @param arr A NULL-terminated array of strings (2D character array).
 * @param c The character to count in the array.
 * @return int The total count of occurrences of `c` in the entire 2D array.
 *         Returns -1 if `arr` is NULL.
 */
int	ft_parse_char_2d_arr(char **arr, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!arr)
		return (-1);
	while (arr[i])
	{
		count += ft_parse_char_arr(arr[i], c);
		i++;
	}
	return (count);
}

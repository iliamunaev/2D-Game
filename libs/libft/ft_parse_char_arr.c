/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_char_arr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:44:09 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/01 14:53:07 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @brief Counts occurrences of a character in a string.
 *
 * This function iterates through a given string (`char *arr`)
 * and counts how many times the specified character `c` appears.
 *
 * @param arr A null-terminated string in which to count occurrences of `c`.
 * @param c The character to count within the string.
 * @return int The total count of occurrences of `c` in the string.
 *         Returns -1 if `arr` is NULL.
 */
int	ft_parse_char_arr(char *arr, char c)
{
	int	i;
	int	count;	

	i = 0;
	count = 0;
	if (!arr)
		return (-1);
	while (arr[i])
	{
		if (arr[i] == c)
			count++;
		i++;
	}
	return (count);
}

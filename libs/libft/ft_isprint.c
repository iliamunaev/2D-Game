/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:48:51 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/18 12:01:39 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks if a character is printable.
 *
 * This function tests whether the given character `c` is a printable
 * character, including the space character (characters in the range
 * 32 to 126).
 *
 * @param c The character to check.
 * @return int Nonzero if the character is printable, 0 otherwise.
 */
int	ft_isprint(char c)
{
	return (c >= 32 && c <= 126);
}

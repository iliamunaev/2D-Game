/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:20:59 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/18 12:08:42 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks if a value represents an ASCII character.
 *
 * This function tests whether the given value `c` is within the
 * ASCII character set range (0 to 127 inclusive).
 *
 * @param c The value to check, typically a character represented as an integer.
 * @return int Nonzero if the value is an ASCII character, 0 otherwise.
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

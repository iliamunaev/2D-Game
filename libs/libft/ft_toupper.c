/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:28:11 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/18 12:47:00 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Converts a lowercase letter to an uppercase letter.
 *
 * This function checks if the input character `c` is a lowercase letter
 * ('a' to 'z'). If it is, the function converts it to the corresponding
 * uppercase letter. If the character is not a lowercase letter, it is
 * returned unchanged.
 *
 * @param c The character to be converted, represented as an integer.
 * @return int The uppercase equivalent of the character if it is lowercase,
 *         or the original character if no conversion was possible.
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	return (c);
}

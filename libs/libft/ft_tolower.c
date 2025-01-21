/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:31:07 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/18 12:46:41 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Converts an uppercase letter to a lowercase letter.
 *
 * This function checks if the input character `c` is an uppercase letter
 * ('A' to 'Z'). If it is, the function converts it to the corresponding
 * lowercase letter. If the character is not an uppercase letter, it is
 * returned unchanged.
 *
 * @param c The character to be converted, represented as an integer.
 * @return int The lowercase equivalent of the character if it is uppercase,
 *         or the original character if no conversion was possible.
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}

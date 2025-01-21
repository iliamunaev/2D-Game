/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:48:35 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/18 11:50:01 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks if a character is a whitespace character.
 *
 * This function determines whether the given character is a
 * whitespace character, which includes:
 * - Space (' ')
 * - Newline ('\n')
 * - Form feed ('\f')
 * - Carriage return ('\r')
 * - Horizontal tab ('\t')
 * - Vertical tab ('\v')
 *
 * @param c The character to check.
 * @return int 1 if the character is a whitespace character, 0 otherwise.
 */

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\f' || c == '\r'
		|| c == '\t' || c == '\v');
}

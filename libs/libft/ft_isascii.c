/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:20:59 by imunaev-          #+#    #+#             */
/*   Updated: 2024/11/06 11:44:09 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  ft_isascii() checks 'c' for an ASCII character (in the range 0 to 127).
**  Return: nonzero if True, else 0.
*/

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

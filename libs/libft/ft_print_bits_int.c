/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:52:02 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/30 22:59:44 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Prints the binary representation of a 32-bit integer.
 *
 * This function takes a 32-bit signed integer (`num`) and prints its
 * binary representation to the standard output. The most significant bit (MSB)
 * is printed first, and the least significant bit (LSB) last.
 * The function correctly handles both positive and negative numbers.
 *
 * @param num The 32-bit integer whose binary representation is to be printed.
 */
void	ft_print_bits_int(int num)
{
	unsigned int	mask;
	char			bit;
	int				i;

	mask = 1U << 31;
	i = 31;
	while (i >= 0)
	{
		bit = '0';
		if (num & mask)
			bit = '1';
		write(1, &bit, 1);
		mask >>= 1;
		i--;
	}
}

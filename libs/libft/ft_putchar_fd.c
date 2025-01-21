/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:17:28 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/18 12:20:50 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Outputs a character to a specified file descriptor.
 *
 * This function writes the character `c` to the file descriptor `fd`.
 * It is useful for sending output to a specific destination, such as
 * standard output, a file, or a pipe.
 *
 * @param c The character to output.
 * @param fd The file descriptor to write to.
 * @return void This function does not return a value.
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

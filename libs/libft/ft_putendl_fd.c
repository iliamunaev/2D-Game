/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:28:23 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/18 12:21:19 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Outputs a string followed by a newline to a specified file descriptor.
 *
 * This function writes the string `s` to the file descriptor `fd`,
 * followed by a newline character. If the string `s` is NULL, the
 * function does nothing.
 *
 * @param s The string to output. If NULL, no action is taken.
 * @param fd The file descriptor to write to.
 * @return void This function does not return a value.
 */
void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:26:06 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/18 12:22:31 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Outputs a string to a specified file descriptor.
 *
 * This function writes the string `s` to the file descriptor `fd`.
 * If the string `s` is NULL, the function does nothing. The length of
 * the string is determined using `ft_strlen`.
 *
 * @param s The string to output. If NULL, no action is taken.
 * @param fd The file descriptor on which to write.
 * @return void This function does not return a value.
 */
void	ft_putstr_fd(char *s, int fd)
{
	if (!s || !fd)
		return ;
	write(fd, s, ft_strlen(s));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:26:06 by imunaev-          #+#    #+#             */
/*   Updated: 2024/11/17 21:56:30 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Outputs the string ’s’ to the given file descriptor.
 * Return: None
 */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || !fd)
		return ;
	write(fd, s, ft_strlen(s));
}

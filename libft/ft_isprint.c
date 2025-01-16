/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:48:51 by imunaev-          #+#    #+#             */
/*   Updated: 2024/11/08 14:38:48 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_isprint() checks if 'c' printable character (including space).
** Return: nonzero if True, else 0.
*/

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

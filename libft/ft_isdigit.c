/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:53:37 by imunaev-          #+#    #+#             */
/*   Updated: 2024/11/06 11:44:22 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_isdigit checks if 'c' is a numeric character (0123456789).
** Return: nonzero if True, else 0.
*/

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

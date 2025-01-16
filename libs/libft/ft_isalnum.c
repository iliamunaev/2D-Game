/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:17:25 by imunaev-          #+#    #+#             */
/*   Updated: 2024/11/06 11:20:20 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_isalnum() checks 'c' for an alphanumeric character;
** it is equivalent to (isalpha(c) || isdigit(c)).
** Return: nonzero if True, esle 0.
*/

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

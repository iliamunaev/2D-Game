/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:52:22 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/27 15:59:24 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


/*
** Joins two strings 's1' and 's2' into a new string.
** Frees 's1' after joining.
** Returns the new string, or NULL if allocation fails.
*/
char	*ft_strjoin_and_free(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*new_str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_str = (char *)malloc(len1 + len2 + 1);
	if (!new_str)
	{
		free(s1);
		return (NULL);
	}
	ft_strcpy(new_str, s1);
	ft_strcpy(new_str + len1, s2);
	free(s1);
	return (new_str);
}




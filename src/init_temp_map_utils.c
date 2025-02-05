/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_temp_map_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:01:58 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/05 12:03:07 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_map_file(const char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_putstr_fd("Error: failed to open map file.\n", 2);
	return (fd);
}

void	trim_2d_array(char **arr)
{
	int	i;
	int	len;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		len = ft_strlen(arr[i]);
		if (len > 0 && arr[i][len - 1] == '\n')
			arr[i][len - 1] = '\0';
		i++;
	}
}

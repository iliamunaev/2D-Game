/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:33:15 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/31 21:36:03 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	init_map(const char *map_file, t_map *map)
{
	t_temp_map	*temp_map;

	temp_map = init_temp_map(map_file);
	if(!temp_map)
	{
		ft_putstr_fd("ERROR: init_map(): init_temp_map failed\n", 2);
		return (INIT_ERROR);
	}
	else
		ft_putstr_fd("SUCCESS: init_map(): init_temp_map -> ok\n", 2);

	printf("INFO: init_map() temp_map->rows: %d, temp_map->cols: %d\n", temp_map->rows, temp_map->cols);

	if(fillup_map(map, temp_map) == INIT_ERROR)
	{
		ft_putstr_fd("ERROR: init_map(): fillup_map() failed\n", 2);
		return (INIT_ERROR);
	}
	else
		ft_putstr_fd("SUCCESS: init_map(): fillup_map() -> ok\n", 2);  // test

	// free temp_map

	return (INIT_SUCCESS);
}

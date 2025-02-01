/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:36:13 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/01 15:00:32 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



t_map	*init_map(const char *map_file)
{
	t_map	*map;
	t_temp_map	*temp_map;

	map = malloc(sizeof(t_map));
	if (!map)
	{
		ft_putstr_fd("ERROR: load_map() map mem alloc failed\n", 2);
		return(NULL);
	}
	else
		ft_putstr_fd("SUCCESS: load_map() map mem alloc\n", 2);

	temp_map = init_temp_map(map_file);
	if(!temp_map)
	{
		ft_putstr_fd("ERROR: init_map(): init_temp_map failed\n", 2);
		return (NULL);
	}
	else
		ft_putstr_fd("SUCCESS: init_map(): init_temp_map -> ok\n", 2);

	printf("INFO: init_map() temp_map->rows: %d, temp_map->cols: %d\n", temp_map->rows, temp_map->cols);

	
	if(!is_valid(temp_map))
	{
		ft_putstr_fd("ERROR: init_temp_map(): is_valid() failed\n", 2);
		return (NULL);
	}
	else 
		ft_putstr_fd("SUCCESS: init_temp_map(): is_valid() -> ok\n", 2);


	if(fillup_map(map, temp_map) == INIT_ERROR)
	{
		ft_putstr_fd("ERROR: init_map(): fillup_map() failed\n", 2);
		return (NULL);
	}
	else
		ft_putstr_fd("SUCCESS: init_map(): fillup_map() -> ok\n", 2);

	return (map);
}

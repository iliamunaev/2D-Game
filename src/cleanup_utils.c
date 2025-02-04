/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:16:46 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/04 13:23:40 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_temp_map(t_temp_map *temp_map)
{
	int i;

	if (!temp_map)
		return ; 
	i = 0;
	while (i < temp_map->rows)
	{
		if (temp_map->layout[i])
			free(temp_map->layout[i]);
		temp_map->layout[i] = NULL;
		i++;
	}
	free(temp_map->layout);
	temp_map->layout = NULL;
	free(temp_map);
}

void	free_map(t_map *map)
{
	int i;

	if (!map)
		return ; 
	i = 0;
	if(map->map[i])
	{
		while (map->map[i])
		{
			if (map->map[i])
				free(map->map[i]);
			map->map[i] = NULL;
			i++;
		}
		free(map->map);
		map->map = NULL;	
	}
	free(map);
}

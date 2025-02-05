/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillup_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:51:07 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/05 13:18:17 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	fillup_layout(t_map *map, t_temp_map *temp_map)
{
	int	i;

	map->map = malloc(map->rows * sizeof(char *));
	if (!map->map)
	{
		ft_putstr_fd("Error: fillup_layout -> malloc 'map->rows' failed\n", 2);
		free(map);
		return (EXIT_FAILURE);
	}
	i = 0;
	while (i < map->rows)
	{
		map->map[i] = ft_strdup(temp_map->layout[i]);
		if (!map->map[i])
		{
			ft_putstr_fd("Error: fillup_layout -> strdup failed\n", 2);
			while (--i >= 0)
				free(map->map[i]);
			free(map->map);
			map->map = NULL;
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	fillup_map(t_map *map, t_temp_map *temp_map)
{
	map->rows = temp_map->rows;
	map->cols = temp_map->cols;
	map->collects = temp_map->collects;
	map->map = NULL;
	if (fillup_layout(map, temp_map) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

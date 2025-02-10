/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillup_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:51:07 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/10 09:52:24 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Allocates and fills the map layout from a temporary map.
 *
 * Allocates memory for the `map->map` array and copies each row from 
 * the temporary map's layout. If allocation fails, it frees any 
 * previously allocated memory and returns an error code.
 *
 * @param map Pointer to the map structure to be populated.
 * @param temp_map Pointer to the temporary map containing the layout data.
 * @return EXIT_SUCCESS on success, EXIT_FAILURE on memory allocation failure.
 */
static int	fillup_layout(t_map *map, t_temp_map *temp_map)
{
	int	i;

	map->map = malloc(map->rows * sizeof(char *));
	if (!map->map)
	{
		ft_putstr_fd("Error: fillup_layout -> malloc 'map->rows' failed\n", 2);
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

/**
 * @brief Copies map properties and initializes its layout.
 *
 * Copies the row and column count from the temporary map, along with 
 * the collectible count. Calls `fillup_layout()` to allocate and copy 
 * the layout. If layout allocation fails, it returns an error code.
 *
 * @param map Pointer to the map structure to be initialized.
 * @param temp_map Pointer to the temporary map with the source data.
 * @return EXIT_SUCCESS on success, EXIT_FAILURE if memory allocation fails.
 */
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

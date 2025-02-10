/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:36:13 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/10 10:02:48 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Initializes the map structure from a given file.
 *
 * Loads a temporary map from the specified file, validates it, and 
 * allocates memory for the final map structure. If memory allocation 
 * or validation fails, it cleans up and returns NULL.
 *
 * @param map_file Path to the map file.
 * @return Pointer to the initialized map structure, or NULL on failure.
 */
t_map	*init_map(const char *map_file)
{
	t_map		*map;
	t_temp_map	*temp_map;

	temp_map = init_temp_map(map_file);
	if (!temp_map)
		return (NULL);
	if (!is_valid(temp_map))
		return (NULL);
	map = malloc(sizeof(t_map));
	if (!map)
	{
		free_temp_map(temp_map);
		ft_putstr_fd("Error: init_map -> map malloc failed.\n", 2);
		return (NULL);
	}
	if (fillup_map(map, temp_map) == EXIT_FAILURE)
	{
		free_temp_map(temp_map);
		free_map(map);
		return (NULL);
	}
	free_temp_map(temp_map);
	return (map);
}

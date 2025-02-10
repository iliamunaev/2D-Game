/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:55:07 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/10 10:08:33 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Validates the structure and contents of the temporary map.
 *
 * Checks if the map meets all necessary criteria, including:
 * - Ensuring walls are properly placed.
 * - Verifying the column count does not exceed the maximum.
 * - Confirming the map has a rectangular shape.
 * - Validating that only allowed characters are present.
 * - Running additional custom validation checks.
 *
 * If any of these checks fail, the temporary map is freed, and the function 
 * returns false.
 *
 * @param temp_map Pointer to the temporary map structure.
 * @return true if the map is valid, false otherwise.
 */
bool	is_valid(t_temp_map *temp_map)
{
	if (!is_walls(temp_map)
		|| !is_in_max_columns(temp_map)
		|| !is_rectangular(temp_map)
		|| !is_valid_chars(temp_map)
		|| !additional_validation(temp_map))
	{
		free_temp_map(temp_map);
		return (false);
	}
	return (true);
}

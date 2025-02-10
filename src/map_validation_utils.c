/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:34:22 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/10 10:14:13 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Restores the original characters in the temporary map.
 *
 * Converts previously marked characters ('L', 'X', 'O', 'A') back to their 
 * original representations (floor, exit, collectible, player).
 *
 * @param temp_map Pointer to the temporary map structure.
 * @param c The character to process.
 * @param y Row coordinate.
 * @param x Column coordinate.
 */
static void	process_char(t_temp_map *temp_map, char c, int y, int x)
{
	if (c == 'L')
		temp_map->layout[y][x] = FLOOR;
	else if (c == 'X')
	{
		temp_map->layout[y][x] = EXIT;
		temp_map->exit++;
	}
	else if (c == 'O')
	{
		temp_map->layout[y][x] = COLLECTIBLE;
		temp_map->collects++;
	}
	else if (c == 'A')
		temp_map->layout[y][x] = PLAYER;
}

/**
 * @brief Restores the map layout after validation.
 *
 * Iterates through the map and restores all modified characters 
 * (used in validation) back to their original values.
 *
 * @param temp_map Pointer to the temporary map structure.
 */
void	revert_map(t_temp_map *temp_map)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (y < temp_map->rows)
	{
		x = 0;
		while (x < temp_map->cols)
		{
			c = temp_map->layout[y][x];
			process_char(temp_map, c, y, x);
			x++;
		}
		y++;
	}
}

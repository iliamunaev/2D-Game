/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:16:46 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/10 09:51:21 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Frees memory allocated for a temporary map structure.
 *
 * Iterates through each row of the temporary map's layout, freeing 
 * allocated memory before freeing the layout itself and the main 
 * structure.
 *
 * @param temp_map Pointer to the temporary map structure to be freed.
 */
void	free_temp_map(t_temp_map *temp_map)
{
	int	i;

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

/**
 * @brief Frees memory allocated for a map structure.
 *
 * Deallocates memory assigned to the map, including its 2D layout 
 * before freeing the map structure itself.
 *
 * @param map Pointer to the map structure to be freed.
 */
void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->map)
	{
		i = 0;
		while (i < map->rows)
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
		map->map = NULL;
	}
	free(map);
}

/**
 * @brief Cleans up allocated memory for the game and sprite structures.
 *
 * Releases resources allocated to the game map and game structure.
 * Also frees sprite resources before printing a farewell message.
 *
 * @param game Pointer to the game structure to be freed.
 * @param sprites Pointer to the sprite structure to be freed.
 */
void	cleanup(t_game *game, t_sprites *sprites)
{
	if (game)
	{
		free_map(game->map);
		free(game);
	}
	if (sprites)
		free(sprites);
	ft_putstr_fd("See you!\n", 1);
}

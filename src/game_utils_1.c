/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:41:29 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/10 17:50:48 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Initializes the four corner positions of an entity.
 *
 * Calculates the tile-based coordinates for the top-left, top-right,
 * bottom-left, and bottom-right corners of an entity based on the
 * next movement position.
 *
 * @param corner Pointer to the corner structure to be initialized.
 * @param next_x The next x-coordinate of the entity.
 * @param next_y The next y-coordinate of the entity.
 */
void	init_corners(t_corner *corner, int next_x, int next_y)
{
	corner->tlx = next_x / TILE_SIZE;
	corner->tly = next_y / TILE_SIZE;
	corner->trx = (next_x + TILE_SIZE - 1) / TILE_SIZE;
	corner->try = next_y / TILE_SIZE;
	corner->blx = next_x / TILE_SIZE;
	corner->bly = (next_y + TILE_SIZE - 1) / TILE_SIZE;
	corner->brx = (next_x + TILE_SIZE - 1) / TILE_SIZE;
	corner->bry = (next_y + TILE_SIZE - 1) / TILE_SIZE;
}

/**
 * @brief Checks if a given tile contains a collectible item.
 *
 * Evaluates whether the specified tile character represents a collectible ('C').
 *
 * @param collectable Character representing the tile content.
 * @return true if the tile contains a collectible, false otherwise.
 */
bool	is_cltbl(char collectable)
{
	return (collectable == 'C');
}

/**
 * @brief Moves the player to a new position and updates movement count.
 *
 * Updates the player's x and y coordinates, increments the movement count,
 * and prints the number of movements every `DEVIDER` steps.
 *
 * @param game Pointer to the game structure.
 * @param nx The new x-coordinate of the player.
 * @param ny The new y-coordinate of the player.
 */
void	move_player(t_game *game, int nx, int ny)
{
	game->sprites->player->instances[0].x = nx;
	game->sprites->player->instances[0].y = ny;
	game->moves++;
	ft_printf("Movements count: %d\n", game->moves);
}

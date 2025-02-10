/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:15:33 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/30 12:45:00 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Renders a single sprite on the game window.
 *
 * Selects the appropriate sprite based on the target character ('0' for floor, 
 * '1' for wall, 'C' for collectible, 'E' for exit, 'P' for player) and places 
 * it at the specified row and column. If an error occurs,
 * an error message is printed.
 *
 * @param game Pointer to the game structure.
 * @param target The character representing the sprite type.
 * @param row The row position of the sprite.
 * @param col The column position of the sprite.
 * @return true if rendering is successful, false otherwise.
 */
static bool	render_sprite(t_game *game, char target, int row, int col)
{
	mlx_image_t	*sprite;

	sprite = NULL;
	if (target == '0')
		sprite = game->sprites->floor;
	else if (target == '1')
		sprite = game->sprites->wall;
	else if (target == 'C')
		sprite = game->sprites->collects;
	else if (target == 'E')
		sprite = game->sprites->exit;
	else if (target == 'P')
		sprite = game->sprites->player;
	if (!sprite)
	{
		ft_putstr_fd("Error: assign sprite ptr to game failed\n", 2);
		return (false);
	}
	if (mlx_image_to_window(game->mlx, sprite,
			col * TILE_SIZE, row * TILE_SIZE) == -1)
	{
		ft_putstr_fd("Error: render_sprite -> mlx_image_to_window failed\n", 2);
		return (false);
	}
	return (true);
}

/**
 * @brief Renders all instances of a specific tile type.
 *
 * Iterates through the game map and renders all occurrences of 
 * the specified tile type (walls, collectibles, exits, or player).
 *
 * @param game Pointer to the game structure.
 * @param target The character representing the tile type to be rendered.
 * @return true if rendering is successful, false otherwise.
 */
static bool	render(t_game *game, char target)
{
	int		x;
	int		y;
	char	**position;

	position = game->map->map;
	y = 0;
	while (y < game->map->rows)
	{
		x = 0;
		while (x < game->map->cols)
		{
			if (position[y][x] == target)
			{
				if (!render_sprite(game, target, y, x))
				{
					ft_putstr_fd("Error: render -> tiles failed\n", 2);
					return (false);
				}
			}
			x++;
		}
		y++;
	}
	return (true);
}

/**
 * @brief Renders the floor tiles across the entire game map.
 *
 * Iterates through all rows and columns of the map, rendering the floor tiles.
 * If rendering fails, an error message is printed.
 *
 * @param game Pointer to the game structure.
 * @param target The character representing the floor tile.
 * @return true if rendering is successful, false otherwise.
 */
static bool	render_floor(t_game *game, char target)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->map->rows)
	{
		x = 0;
		while (x < game->map->cols)
		{
			if (!render_sprite(game, target, y, x))
			{
				ft_putstr_fd("Error: render_floor -> failed\n", 2);
				return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}

/**
 * @brief Renders the entire game map.
 *
 * Assigns the sprite structure to the game and sequentially renders 
 * the floor, walls, collectibles, exit, and player sprites onto the window.
 * If any rendering step fails, the function returns EXIT_FAILURE.
 *
 * @param game Pointer to the game structure.
 * @param sprites Pointer to the sprite structure.
 * @return EXIT_SUCCESS if rendering is successful, EXIT_FAILURE otherwise.
 */
int	render_game(t_game *game, t_sprites *sprites)
{
	game->sprites = sprites;
	if (!render_floor(game, FLOOR))
		return (EXIT_FAILURE);
	if (!render(game, WALL))
		return (EXIT_FAILURE);
	if (!render(game, COLLECTIBLE))
		return (EXIT_FAILURE);
	if (!render(game, EXIT))
		return (EXIT_FAILURE);
	if (!render(game, PLAYER))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

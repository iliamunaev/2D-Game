/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:36:25 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/27 15:16:18 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_tile(t_game *game, int y, int x)
{
	char			tile;
	mlx_image_t		*img;

	tile = game->map->layout[y][x];
	img = NULL;

	if (tile == '1')
		img = game->sprites->wall;
	else if (tile == '0')
		img = game->sprites->floor;
	else if (tile == 'C')
		img = game->sprites->collectible;
	else if (tile == 'E')
		img = game->sprites->exit;
	else if (tile == 'P')
		img = game->sprites->player;
	if (!img)
	{
		// err
	}
	mlx_image_to_window(game->mlx, img, x * TILE_SIZE, y * TILE_SIZE);
	// Free the temporary image
	mlx_delete_image(game->mlx, img);
}

void	flood_fill(t_game *game, char target, int row, int col)
{
	if(col < 0 || row < 0 || col >= MAX_COLUMNS || row >= MAX_ROWS)
		return ;
	render_tile(game, row, col);
	flood_fill(game, target, row + 1, col);
	flood_fill(game, target, row, col + 1);
	flood_fill(game, target, row - 1, col);
	flood_fill(game, target, row, col - 1);
}

void	render_dynamic(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	flood_fill(game, 'C', row, col);
	flood_fill(game, 'P', row, col);
	flood_fill(game, 'E', row, col);
}

void	render_static(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	flood_fill(game, '0', row, col);
	flood_fill(game, '1', row, col);
}

void	run_game(t_game *game)
{
	(void)game; // test
	//handle_input_loop(game);
	//render_dynamic(game);
	
}

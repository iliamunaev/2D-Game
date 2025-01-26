/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rander_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:36:25 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/26 13:36:26 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void render_tile(t_game *game, int x, int y)
{
	char			tile;
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	tile = game->map->layout[y][x];
	texture = NULL;

	if (tile == '1')
		texture = game->sprites->wall;
	else if (tile == '0')
		texture = game->sprites->floor;
	else if (tile == 'C')
		texture = game->sprites->collectible;
	else if (tile == 'E')
		texture = game->sprites->exit;
	else if (tile == 'P')
		texture = game->sprites->player;

	if (texture)
	{
		img = mlx_texture_to_image(game->mlx, texture);
		mlx_image_to_window(game->mlx, img, x * TILE_SIZE, y * TILE_SIZE);

		// Free the temporary image
		mlx_delete_image(game->mlx, img);
	}
}

void	render_game(t_game *game)
{
	int	x;
	int	y;
	// Clear the previous frame
	mlx_clear_window(game->mlx);

	// Render the map
	y = 0;
	while (y < game->map->rows)
	{
		x = 0;
		while(x < game->map->columns)
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
}

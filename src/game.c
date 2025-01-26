/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:36:20 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/26 13:36:21 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;
	char	next_tile;

	new_x = game->player->x + dx;
	new_y = game->player->y + dy;

	// prevent movemant out of map
	if (new_x < 0 || new_x >= game->map->columns || new_y < 0 || new_y >= game->map->rows)
		return ;

	// preventr movement into walls
	next_tile = game->map->layout[new_y][new_x];
	if (next_tile == '1')
		return ;

	if (next_tile == 'C')
	{
		// collect() re-render()
		game->player->collected++;
		game->map->collectibles--;
	}

	if (next_tile == 'E' && game->map->collectibles == 0)
	{
		printf("Congratulations! You've won the game in %d moves!\n", game->move_count);
		game->running = false;
	}

	game->player->x = new_x;
	game->player->y = new_y;

	game->move_count++;

	ft_printf("Moves: %d\n", game->move_count);
}

void	handle_input_loop(t_game *game)
{
	mlx_key_data_t	keydata;

	while (mlx_poll_events(game->mlx, &keydata))
	{
		if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		{
			if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
				move_player(game, 0, -1);
			else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
				move_player(game, 0, 1);
			else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
				move_player(game, -1, 0);
			else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
				move_player(game, 1, 0);
			else if (keydata.key == MLX_KEY_ESCAPE)
				game->running = false;
		}
	}
}


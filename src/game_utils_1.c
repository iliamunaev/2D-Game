/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:41:29 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/05 11:55:50 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_corners(t_corner *corner, int next_x, int next_y)
{
	corner->t_left_x = next_x / TILE_SIZE;
	corner->tly = next_y / TILE_SIZE;
	corner->trx = (next_x + TILE_SIZE - 1) / TILE_SIZE;
	corner->try = next_y / TILE_SIZE;
	corner->blx = next_x / TILE_SIZE;
	corner->bly = (next_y + TILE_SIZE - 1) / TILE_SIZE;
	corner->brx = (next_x + TILE_SIZE - 1) / TILE_SIZE;
	corner->bry = (next_y + TILE_SIZE - 1) / TILE_SIZE;
}

bool	is_cltbl(char collectable)
{
	return (collectable == 'C');
}

void	move_player(t_game *game, int nx, int ny)
{
	game->sprites->player->instances[0].x = nx;
	game->sprites->player->instances[0].y = ny;
	game->moves++;
	ft_printf("Movements count: %d\n", game->moves);
}

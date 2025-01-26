/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:35:24 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/26 13:43:03 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void create_sprites(t_game *game)
{

	game->sprites->collectible =  mlx_load_png("../sprites/collectible.png");
	if (!game->sprites->collectible)
		error();

	game->sprites->wall =  mlx_load_png("../sprites/wall.png");
	if (!game->sprites->wall)
		error();

	game->sprites->exit =  mlx_load_png("../sprites/exit.png");
	if (!game->sprites->exit)
		error();

	game->sprites->floor =  mlx_load_png("../sprites/floor.png");
	if (!game->sprites->floor)
		error();

	game->sprites->player =  mlx_load_png("../sprites/player.png");
	if (!game->sprites->player)
		error();

}


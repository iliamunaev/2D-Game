/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:59:26 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/27 14:11:04 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_player(t_game *game)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if(!player)
	{
		return (INIT_ERROR);

	}
	player->y = 0;
	player->x = 0;
	player->collected = 0;
	game->player = player;

	return(INIT_SUCCESS);
}
t_game	*init_game(t_map *map)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if(!game)
	{
		// err msg
		return (NULL);
	}

	game->map = map;
	if (!game->map)
	{
		// error msg
		return (NULL);
	}

	game->mlx = mlx_init(game->map->columns * TILE_SIZE, game->map->rows * TILE_SIZE, "So Long", true); // tested
	if (!game->mlx)
	{
		ft_putstr_fd("main(): Error mlx_init\n", 2);
		return (NULL);
	}

	game->sprites = malloc(sizeof(t_sprites));
	if (!game->sprites)
	{
		// error msg
		return (NULL);
	}
	load_textures(game);

	game->player = malloc(sizeof(t_player));
	if (!game->player)
	{
		// err msg
		return (NULL);
	}
	if(init_player(game) == INIT_ERROR)
	{
		// err msg
		return (NULL);
	}
	game->move_count = 0;
	game->running = true;

	return(game);
}


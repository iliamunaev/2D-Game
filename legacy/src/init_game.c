/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:59:26 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/31 21:23:39 by imunaev-         ###   ########.fr       */
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
		ft_putstr_fd("init_game(): Error mem alloc for game\n", 2);
		return (NULL);
	}

	game->map = map;

	game->mlx = mlx_init(game->map->cols * TILE_SIZE, game->map->rows * TILE_SIZE, "So Long", true); // tested
	if (!game->mlx)
	{
		ft_putstr_fd("init_game(): Error mlx_init\n", 2);
		return (NULL);
	}

	game->sprites = malloc(sizeof(t_sprites));
	if (!game->sprites)
	{
		ft_putstr_fd("init_game(): Error mem alloc for sprites\n", 2);
		return (NULL);
	}

	return(game);
}


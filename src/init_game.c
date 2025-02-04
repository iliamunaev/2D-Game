/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:15:29 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/05 00:30:31 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*init_game(t_map *map)
{
	t_game		*game;

	game = malloc(sizeof(t_game));
	if(!game)
	{
		ft_putstr_fd("Error: init_game -> malloc game memory allocation failed\n", 2);
		return (NULL);
	}
	game->mlx = mlx_init(map->cols * TILE_SIZE, map->rows * TILE_SIZE, "So Long", true);

	if (!game->mlx)
	{
		free_map(map);
		free(game);
		ft_putstr_fd("Error: init_game -> mlx_init failed\n", 2);
		return (NULL);
	}
	game->map = map;
	game->sprites = NULL;
	game->collects = map->collects;
	game->moves = 0;
	game->is_exit = false;
	return (game);
}

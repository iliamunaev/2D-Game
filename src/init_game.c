/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:15:29 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/05 13:07:53 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_game	*init_mlx(t_map *map)
{
	t_game		*game;

	game = malloc(sizeof(t_game));
	if (!game)
	{
		ft_putstr_fd("Error: init_game -> malloc game malloc failed\n", 2);
		return (NULL);
	}
	game->mlx = mlx_init(map->cols * TILE_SIZE,
			map->rows * TILE_SIZE, "So Long", true);
	if (!game->mlx)
	{
		free_map(map);
		game = NULL;
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

t_game	*init_game(const char *map_file)
{
	t_map	*map;
	t_game	*game;

	map = init_map(map_file);
	if (!map)
		return (NULL);
	game = init_mlx(map);
	if (!game)
	{
		free_map(map);
		return (NULL);
	}
	return (game);
}

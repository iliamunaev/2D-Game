/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:15:29 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/31 16:03:56 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*init_game(t_map *map)
{	
	t_game		*game;	

	game = malloc(sizeof(t_game));
	if(!game)
	{
		ft_putstr_fd("ERROR: init_game(): game memory allocation failed\n", 2);
		return (NULL);
	}
	else
		ft_putstr_fd("SUCCESS: init_game(): game memory allocation -> ok\n", 2);
		
	game->mlx = mlx_init(map->cols * TILE_SIZE, map->rows * TILE_SIZE, "So Long", true);
	if (!game->mlx)
	{
		ft_putstr_fd("ERROR: init_game(): mlx_init\n", 2);
		return (NULL);
	}	
	else
		ft_putstr_fd("SUCCESS: init_game(): mlx_init\n", 2);
	
	game->map = map;
	game->sprites = NULL;
	game->collects = map->collects;
	game->is_exit = false;
	game->is_running = false;
	
	return (game);
}

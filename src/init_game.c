/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:15:29 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/30 15:57:06 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


t_game	*init_game()
{
	
	t_sprites	*sprites;
	t_map		*map;
	t_game		*game;

	// sprites
	sprites = malloc(sizeof(t_sprites));
	if(!sprites)
	{
		ft_putstr_fd("ERROR: init_game(): sprites memory allocation failed\n", 2);
		return (NULL);
	}
	else 
		ft_putstr_fd("SUCCESS: init_game(): sprites memory allocation -> ok\n", 2);  // test
	
	
	// map
	map = malloc(sizeof(t_map));
	if(!map)
	{
		ft_putstr_fd("ERROR: init_game(): map memory allocation failed\n", 2);
		return (NULL);
	}
	else 
		ft_putstr_fd("SUCCESS: init_game(): map memory allocation -> ok\n", 2);  // test

	map->layout = malloc(sizeof(char *) * 5); // Allocate rows
	if(!map->layout)
	{
		ft_putstr_fd("ERROR: init_game(): map->layout memory allocation failed\n", 2);
		return (NULL);
	}
	else 
		ft_putstr_fd("SUCCESS: init_game(): map->layout memory allocation -> ok\n", 2);  // test
	
	// delete
		
	for (int i = 0; i < 5; i++)
		map->layout[i] = malloc(sizeof(char) * 5); // Allocate columns

	// Fill values manually
	char temp_layout[5][5] = {
		{'P', '0', '0', '0', '0'},
		{'0', '0', '0', '0', '0'},
		{'0', '0', '0', '0', '0'},
		{'0', '0', '0', '0', '0'},
		{'0', '0', '0', '0', '0'}
	};
	
	ft_putstr_fd("INFO: init_game(): printing new map\n", 2);  // test

	// Copy values into `map->layout`
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			map->layout[i][j] = temp_layout[i][j];
	
	int j = 0;
	while(j < 5)
	{
		printf("[%s]\n", map->layout[j]);
		j++;
	}
	

	printf("INFO: map mem address after alloc: %p\n", map);


	map->player = 0;
	map->collectables = 0;
	map->exit = 0;
	map->is_surrounded_walls = false;
	map->is_exit_availble = false;
	map->is_collectebles_availble = false;
	map->is_valid = false;
	
	

	// game	

	game = malloc(sizeof(t_game));
	if(!game)
	{
		ft_putstr_fd("ERROR: init_game(): game memory allocation failed\n", 2);
		return (NULL);
	}
	else
		ft_putstr_fd("SUCCESS: init_game(): game memory allocation -> ok\n", 2);  // test

	game->running = 0;
	sprites->player = NULL;
	game->sprites = sprites;


	game->map = map;	
	printf("INFO: game->map mem address assigned to game: %p\n", game->map);


	return (game);
}

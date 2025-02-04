/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:36:07 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/04 11:47:37 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	main(int ac, char **av)
{
	(void)ac;  // add 
	
	t_map		*map;	
	t_sprites	*sprites;
	t_game		*game;
	const char 	*map_file;

	map_file = av[1];
/*
	if(!is_path_valid(map_file))
	{
		ft_putstr_fd("ERROR: main(): is_path_valid()\n", 2);
		return (EXIT_FAILURE);
	}	
	else 
		ft_putstr_fd("SUCCESS: main(): is_path_valid()\n", 2);

	*/

	// Step 1: load map
	map = init_map(map_file);
	if(!map)
	{		
		ft_putstr_fd("Error: main(): init_map()\n", 2);
		return(EXIT_FAILURE);
	}
	else 
		ft_putstr_fd("SUCCESS: main(): load_map()\n", 2);

		
	// Step 2: init game
	game = init_game(map);
	if(!game)
	{
		ft_putstr_fd("ERROR: main(): init_game()\n", 2);
		return EXIT_FAILURE;
	}	
	else 
		ft_putstr_fd("SUCCESS: main(): init_game()\n", 2);
	
	// Step 3: load sprites
	sprites = load_sprites(game);
	if(!sprites)
	{		
		ft_putstr_fd("ERROR: main(): load_sprites()\n", 2);
		return(EXIT_FAILURE);
	}
	else 
		ft_putstr_fd("SUCCESS: main(): load_sprites()\n", 2);


	// Step 4: render game
	if (render_game(game, sprites) == EXIT_FAILURE)
	{
		ft_putstr_fd("ERROR: main(): render_game()\n", 2);
		return EXIT_FAILURE;
	}
	else
		ft_putstr_fd("SUCCESS: main(): render_game()\n", 2);
	
	// Step 5: run the game
	//mlx_key_hook(game->mlx, key_handler, game);
	mlx_loop_hook(game->mlx, game_loop, game);

	ft_putstr_fd("SUCCESS: main(): game is running!\n", 2);  // test
	
	// Start event loop
	mlx_loop(game->mlx);	
	
	mlx_terminate(game->mlx);
	
	ft_putstr_fd("SUCCESS: main(): game is terminated!\n", 2);  // test

    ft_printf("See you!\n");
	
	//cleanup_game(game);
	return EXIT_SUCCESS;
}

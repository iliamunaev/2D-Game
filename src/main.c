/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:36:07 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/30 17:59:00 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//	char map[67][120] = {0};


int32_t	main(int ac, char **av)
{
	(void)ac;
	
	t_game		*game;
	t_map		*map;	
	const char *file_path;

	file_path = av[1];
	
	game = init_game();
	if(!game)
	{
		ft_putstr_fd("ERROR: main(): init_game()\n", 2);
		return EXIT_FAILURE;
	}	
	else 
		ft_putstr_fd("SUCCESS: main(): init_game()\n", 2);

	

	if (!(game->mlx = mlx_init(MAX_SCREEN_WIDTH, MAX_SCREEN_HEIGHT, "so_long", true)))
	{		
		ft_putstr_fd("ERROR: main(): mlx_init()\n", 2);
		return(EXIT_FAILURE);
	}
	else 
		ft_putstr_fd("SUCCESS: main(): mlx_init()\n", 2);


	map = load_map(file_path);
	if(!map)
	{		
		ft_putstr_fd("ERROR: main(): load_map()\n", 2);
		return(EXIT_FAILURE);
	}
	else 
		ft_putstr_fd("SUCCESS: main(): load_map()\n", 2);


	if(!load_textures(game))
	{	
		ft_putstr_fd("ERROR: main(): load_textures()\n", 2);
		return EXIT_FAILURE;
	}
	else
		ft_putstr_fd("SUCCESS: main(): load_textures()\n", 2);
		
	if (!render_game(game))
	{
		ft_putstr_fd("ERROR: main(): render_game()\n", 2);
		return EXIT_FAILURE;
	}
	else
		ft_putstr_fd("SUCCESS: main(): render_game()\n", 2);

	mlx_loop_hook(game->mlx, key_handler, game);

	ft_putstr_fd("SUCCESS: main(): game is running!\n", 2);  // test
	
	// Start event loop
	mlx_loop(game->mlx);	
	
	mlx_terminate(game->mlx);
	
	ft_putstr_fd("SUCCESS: main(): game is terminated!\n", 2);  // test

	
	//cleanup_game(game);
	return EXIT_SUCCESS;
}

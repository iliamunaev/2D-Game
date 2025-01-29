/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:36:07 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/28 12:19:49 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void key_handler(struct mlx_key_data key_data, void *param)
{
    t_game *game = (t_game *)param;

    if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
    {
        game->running = false; // Stop the game loop on ESC key press
    }
}

int	main(int ac, char **av)
{


	t_game	*game;
	t_map	*map;
	t_monitor *monitor;
    
	if (ac != 2)
		clean_up_game(NULL, NULL, "Error: no map attached\n", EXIT_FAILURE);
	
	monitor = get_monitor_size();	// tested
	if(!monitor)
		printf("get_monitor_size(): ERROR\n");
	printf("monitor hight: %d\n", monitor->height);
	printf("monitor wigth: %d\n", monitor->width);

		
		
	map = load_map(av[1], monitor);
	if(!map)
		printf("load_map(): ERROR\n");
	else
		printf("load_map(): SUCCESS\n");
	
		
	free(monitor);
			
	return 1;
	
	game = init_game(map);
	
	
	if(!game)
		clean_up_game(game, map, "Error: game init failure\n", EXIT_FAILURE);
	
	render_static(game);	
	run_game(game);
	
	mlx_key_hook(game->mlx, key_handler, &game->running);
	
	while (game->running)
	{		
		mlx_loop(game->mlx);
	}
	mlx_terminate(game->mlx);
	
	return(EXIT_SUCCESS);
}

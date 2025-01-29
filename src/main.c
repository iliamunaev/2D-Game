/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:36:07 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/29 15:13:43 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//	char map[67][120] = {0};

void key_handler(void *param)
{
    t_game *game = (t_game *)param;

    if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
    {
        mlx_close_window(game->mlx);
		
		//Deletes an image and removes it from the render queue.
		mlx_delete_image(game->mlx, game->sprites->player);
    }
}


int32_t	main(void)
{
	t_game	*game;


	game = init_game();
	if(!game)
	{
		ft_putstr_fd("ERROR: main(): init_game()\n", 2);
		return EXIT_FAILURE;
	}
	else 
		ft_putstr_fd("SUCCESS: main(): init_game() -> ok\n", 2);
		

	if (!(game->mlx = mlx_init(MAX_SCREEN_WIDTH, MAX_SCREEN_HEIGHT, "so_long", true)))
	{		
		// clean
		return(EXIT_FAILURE);
	}
	else 
		ft_putstr_fd("SUCCESS: main(): mlx_init() -> ok\n", 2);  // test


	if(!load_textures(game))
	{	
		ft_putstr_fd("ERROR: main(): load_textures()\n", 2);
		return EXIT_FAILURE;
	}
	else
		ft_putstr_fd("SUCCESS: main(): load_textures() -> ok\n", 2);  // test
		


	if (!render_game(game))
	{
		ft_putstr_fd("ERROR: main(): render_game()\n", 2);
		return EXIT_FAILURE;
	}
	else
		ft_putstr_fd("SUCCESS: main(): render_game() -> ok\n", 2);  // test



	// key event handling
	mlx_loop_hook(game->mlx, key_handler, game);

	ft_putstr_fd("SUCCESS: main(): game is running!\n", 2);  // test
	
	// Start event loop
	mlx_loop(game->mlx);	
	
	mlx_terminate(game->mlx);
	
	ft_putstr_fd("SUCCESS: main(): game is terminated!\n", 2);  // test

	
	//cleanup_game(game);
	return EXIT_SUCCESS;
}

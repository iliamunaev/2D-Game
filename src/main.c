/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:21:16 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/10 17:49:31 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Main entry point for the game.
 *
 * Handles argument parsing, initializes the game and its components,
 * and starts the game loop. If any initialization step fails,
 * the program exits with an error status.
 *
 * @param ac Argument count.
 * @param av Argument vector.
 * @return EXIT_SUCCESS if the game runs successfully, EXIT_FAILURE on error.
 */
int	main(int ac, char **av)
{
	const char	*map_file;
	t_game		*game;
	t_sprites	*sprites;

	if (handle_arguments(ac, av, &map_file) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	game = init_game(map_file);
	if (!game)
		return (EXIT_FAILURE);
	sprites = init_sprites(game);
	if (!sprites)
		return (EXIT_FAILURE);
	if (render_game(game, sprites) == EXIT_FAILURE)
	{
		cleanup(game, sprites);
		return (EXIT_FAILURE);
	}
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	cleanup(game, sprites);
	return (EXIT_SUCCESS);
}

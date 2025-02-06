/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:21:16 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/06 13:09:11 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

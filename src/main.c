/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:36:07 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/05 08:27:07 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	main(int ac, char **av)
{
	t_map		*map;
	t_sprites	*sprites;
	t_game		*game;
	const char 	*map_file;

	if(ac != 2)
	{
		ft_putstr_fd("Error: Add map.\n", 2);
		return(EXIT_FAILURE);
	}
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

	map = init_map(map_file);
	if(!map)
	{
		ft_putstr_fd("Error: main -> init_map failed.\n", 2);
		return(EXIT_FAILURE);
	}
	int i = 0;
	while(i < map->rows)
	{
		printf("%s\n", map->map[i]);
		i++;
	}
	printf("%d\n", map->cols);
	printf("%d\n", map->rows);
	printf("%d\n", map->collects);


	exit(1);


	game = init_game(map);
	if(!game)
	{
		ft_putstr_fd("Error: main ->: init_game failed.\n", 2);
		return EXIT_FAILURE;
	}
	printf("here\n");
	exit(1);
	sprites = load_sprites(game);
	if(!sprites)
	{
		free_map(map);
		free(game);
		ft_putstr_fd("Error: main -> load_sprites failed\n", 2);
		return(EXIT_FAILURE);
	}

	if (render_game(game, sprites) == EXIT_FAILURE)
	{
		ft_putstr_fd("Error: main -> render_game failed.\n", 2);
		return (EXIT_FAILURE);
	}
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free_map(map);
	free(sprites);
	free(game);
	ft_putstr_fd("See you!\n", 1);
	return (EXIT_SUCCESS);
}

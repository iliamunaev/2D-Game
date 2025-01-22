#include "so_long.h"

void cleanup_game(t_game *game)
{
	for (int y = 0; y < game->map->height; y++) {
		free(game->map->layout[y]);
	}
	free(game->map->layout);
	free(game->map);

	free(game->sprites->wall);
	free(game->sprites->floor);
	free(game->sprites->player);
	free(game->sprites->collectible);
	free(game->sprites->exit);
	free(game->sprites);

	free(game->player);
	mlx_terminate(game->mlx);
}














int	main(int ac, char **av)
{
	t_game	*game;
	t_map	*map;

	if (ac != 2)
	{
		ft_putstr_fd("Error: arg != 2\n",2);
		return (EXIT_FAILURE);
	}

	// Step 1: Validate map and load layout
	map = load_map(av[1]);

	if(!map)
	{
		ft_putstr_fd("Error: map is not valid\n",2);
		return (EXIT_FAILURE);
	}

	// Step 2: 
	init_game(game, map);

	// Step 3:

	while (game->running)
	{
		handle_input_loop(game);
		render_game(game);
	}

	cleanup_game(game);

	return (EXIT_SUCCESS);
}

#include "test_so_long.h"

// mlx_t* mlx_init(int32_t width, int32_t height, const char* title, bool resize);


mlx_t	*test_mlx_init(int32_t width, int32_t height, const char* title, bool resize)
{
	mlx_t	*mlx;

	mlx = mlx_init(width, height, title,resize);
	// mlx = NULL;
	if (!mlx)
	{
		printf("test_mlx_init(): Error mlx_init\n");
		return (NULL);
	}
	return (mlx);
}

/*
int	main()
{
	t_game *game;

	game = init_game();
	if(!game)
		return (EXIT_FAILURE);

	game->mlx = test_mlx_init(50 * TILE_SIZE, 50 * TILE_SIZE, "test_game", true);
	if(!game->mlx)
	{
		printf("main(): Error mlx_init\n");
		return (EXIT_FAILURE);
	}

	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
	
}
*/
#include "so_long.h"


t_game	*init_game(t_map *map)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if(!game)
	{
		// err msg
		return -1;
	}

	// init map
	game->map = map;
	if (!game->map)
	{
		// error msg
		return EXIT_FAILURE;
	}

	// init game
	game->mlx = mlx_init(game->map->columns * TILE_SIZE, game->map->rows * TILE_SIZE, "So Long", true);
	if (!game->mlx)
	{
		// error msg
		return EXIT_FAILURE;
	}

	// init sprites
	game->sprites = malloc(sizeof(t_sprites));
	if (!game->sprites)
	{
		// err msg
		return EXIT_FAILURE;
	}
	load_textures(game);

	// init player
	game->player = malloc(sizeof(t_player));
	if (!game->player)
	{
		// err msg
		return EXIT_FAILURE;
	}
	init_player(game->player, game->map);

	game->move_count = 0;
	game->running = true;

	return(game);
}


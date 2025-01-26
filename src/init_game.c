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
		return -1;
	}

	// init game
	game->mlx = mlx_init(game->map->columns * TILE_SIZE, game->map->rows * TILE_SIZE, "So Long", true);
	if (!game->mlx)
	{
		// error msg
		return -1;
	}

	// init sprites
	game->sprites = malloc(sizeof(t_sprites));
	if (!game->sprites)
	{
		// err msg
		return -1;
	}
	load_sprites(game, );


	// init player
	game->player = malloc(sizeof(t_player));
	if (!game->player)
	{
		// err msg
	}

	game->move_count = 0;

	game->running = true;

	// load textures

	// init player's position
	init_player(game->player, game->map);

	return(game);
}


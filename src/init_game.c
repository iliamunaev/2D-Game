#include "so_long.h"


void	init_game(t_game *game, t_map *map)
{
	// init map
	game->map = map;
	if (!game->map)
	{
		// error msg

	}

	// init game
	game->mlx = mlx_init(game->map->columns * TILE_SIZE, game->map->rows * TILE_SIZE, "So Long", true);
	if (!game->mlx)
	{
		// error msg

	}

	// init sprites
	game->sprites = malloc(sizeof(t_sprites));
	if (!game->sprites)
	{
		// err msg
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
}


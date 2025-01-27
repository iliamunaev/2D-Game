#include "test_so_long.h"

t_game	*init_game(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if(!game)
	{
		printf("Error: game malloc failed\n");
		return (NULL);
	}

	game->map = NULL;
	game->mlx = NULL;
	game->sprites = NULL;
	game->player = NULL;
	game->move_count = 0;
	game->running = true;	return(game);
}

static void	clean_up_map(t_map *map)
{
	if(map)
	{
		if(map->layout)
		{

		}
	}
	free(map->layout);
	free(map);
}

static void	clean_up_sprites(t_sprites *sprites)
{
	if(sprites->wall)
		free(sprites->wall);
	if(sprites->floor)
		free(sprites->floor);
	if(sprites->player)
		free(sprites->player);
	if(sprites->collectible)
		free(sprites->collectible);
	if(sprites->exit)
		free(sprites->exit);
	free(sprites);
}

int	clean_up_game(t_game *game, t_map *map, char *msg, int exit_mark)
{
	if(game)
	{
		if(game->map)
			clean_up_map(game->map);
		if (game->sprites)
			clean_up_sprites(game->sprites);
		if (game->player)
			free(game->player);
		mlx_terminate(game->mlx);
		free(game->mlx);
		free(game);
	}
	if(map)
		clean_up_map(map);
	if(msg)
		ft_putstr_fd(msg,2);
	if(exit_mark)
		return(exit_mark);
	return (0);
}
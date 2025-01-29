#include "so_long.h"


t_game	*init_game()
{
	t_game	*game;
	t_sprites	*sprites;

	game = malloc(sizeof(t_game));
	if(!game)
	{
		ft_putstr_fd("ERROR: init_game(): game memory allocation failed\n", 2);
		return (NULL);
	}
	else
		ft_putstr_fd("SUCCESS: init_game(): game memory allocation -> ok\n", 2);  // test

	game->running = 0;


	sprites = malloc(sizeof(t_sprites));
	if(!sprites)
	{
		ft_putstr_fd("ERROR: init_game(): sprites memory allocation failed\n", 2);
		return (NULL);
	}
	else 
		ft_putstr_fd("SUCCESS: init_game(): sprites memory allocation -> ok\n", 2);  // test

	sprites->player = NULL;
	printf("INFO: init_game() sprite memory init to NULL: %p\n", sprites->player);  // test


	game->sprites = sprites;
	printf("INFO: init_game() sprite memory in t_game add: %p\n", game->sprites->player);  // test

	return (game);
}
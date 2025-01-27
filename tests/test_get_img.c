#include "test_so_long.h"


mlx_image_t	*get_img(t_game *game, const char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	img = NULL;

	texture = mlx_load_png(path);
	if(!texture)
	{
		ft_putstr_fd("get_img(): ERROR mlx_load_png\n", 2);
		// exit
	}
	else
		ft_putstr_fd("get_img(): SUCCESS mlx_load_png\n", 2);  // only for test



	img = mlx_texture_to_image(game->mlx, texture);
	if(!img)
	{
		ft_putstr_fd("get_img(): ERROR mlx_texture_to_image\n", 2);
		mlx_delete_texture(texture);
		// exit
	}
	else
		ft_putstr_fd("get_img(): SUCCESS mlx_texture_to_image\n", 2);  // only for test

	mlx_delete_texture(texture);
	
	ft_putstr_fd("get_img(): SUCCESS returning img\n", 2);  // only for test
	return (img);
}

int	main()
{
	t_game *game;
	mlx_image_t	*img;

	game = init_game();
	if(!game)
	{
		printf("main(): Error init_game\n");
		return (EXIT_FAILURE);
	}

	game->mlx = mlx_init(50 * TILE_SIZE, 50 * TILE_SIZE, "test_game", true);
	if(!game->mlx)
	{
		printf("main(): Error mlx_init\n");
		return (EXIT_FAILURE);
	}

	img = get_img(game, "../imgs/fjf.png");
	if(!img)
		printf("main(): ERROR get_img\n");
	else 
		printf("main(): SUCCESS get_img\n");

	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
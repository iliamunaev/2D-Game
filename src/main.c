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

void move_player(t_game *game, int dx, int dy) {
    int new_x = game->player->x + dx;
    int new_y = game->player->y + dy;

    if (new_x < 0 || new_x >= game->map->width || new_y < 0 || new_y >= game->map->height)
        return; // Prevent out-of-bounds movement

    char next_tile = game->map->layout[new_y][new_x];
    if (next_tile == '1') // Prevent movement into walls
        return;

    if (next_tile == 'C') {
        game->player->collected++;
        game->map->collectible_count--;
    }

    if (next_tile == 'E' && game->map->collectible_count == 0) {
        printf("Congratulations! You've won the game in %d moves!\n", game->move_count);
        game->running = false;
    }

    game->player->x = new_x;
    game->player->y = new_y;
    game->move_count++;
    printf("Moves: %d\n", game->move_count);
}

void render_tile(t_game *game, int x, int y) {
    char tile = game->map->layout[y][x];
    mlx_texture_t *texture = NULL;

    if (tile == '1')
        texture = game->sprites->wall;
    else if (tile == '0')
        texture = game->sprites->floor;
    else if (tile == 'C')
        texture = game->sprites->collectible;
    else if (tile == 'E')
        texture = game->sprites->exit;
    else if (tile == 'P')
        texture = game->sprites->player;

    if (texture) {
        mlx_image_t *img = mlx_texture_to_image(game->mlx, texture);
        mlx_image_to_window(game->mlx, img, x * TILE_SIZE, y * TILE_SIZE);
        mlx_delete_image(game->mlx, img); // Free the temporary image
    }
}

void render_game(t_game *game) {
    mlx_clear_window(game->mlx); // Clear the previous frame

    // Render the map
    for (int y = 0; y < game->map->height; y++) {
        for (int x = 0; x < game->map->width; x++) {
            render_tile(game, x, y);
        }
    }

    // Optionally: Add other UI elements like move count
}

void handle_input_loop(t_game *game) {
    mlx_key_data_t keydata;

    while (mlx_poll_events(game->mlx, &keydata)) {
        if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT) {
            if (keydata.key == MLX_KEY_W)
                move_player(game, 0, -1);
            else if (keydata.key == MLX_KEY_S)
                move_player(game, 0, 1);
            else if (keydata.key == MLX_KEY_A)
                move_player(game, -1, 0);
            else if (keydata.key == MLX_KEY_D)
                move_player(game, 1, 0);
            else if (keydata.key == MLX_KEY_ESCAPE)
                game->running = false;
        }
    }
}


void	init_game(t_game *game, const char *map_file)
{
	game->mlx = mlx_init(800, 600, "So Long", true);
	if (!game->mlx)
		exit_with_error("Failed to initialize MLX42");



	game->sprites = malloc(sizeof(t_sprites));
	if (!game->sprites)
		exit_with_error("Failed to allocate memory for sprites");

	game->player = malloc(sizeof(t_player));
	if (!game->player)
		exit_with_error("Failed to allocate memory for player");

	load_map(game->map, map_file);           // Load and validate map
	load_sprites(game->mlx, game->sprites); // Load textures
	init_player(game->player, game->map);   // Initialize player's position
	game->move_count = 0;
	game->running = true;
}
char	**get_layout(char *map_file)
{
	char **layout;

	get_ne


	return (layout);
}

t_map	*validate_map(char *map_file)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		exit_with_error("Failed to allocate memory for map");
	map->columns = 0;
	map->rows = 0;
	map->collectible_count = 0;
	map->layout = get_layout(map_file);
	if(!map->layout)
	{
		free(map);
		return NULL;
	}
	return (map);
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

	map = validate_map(av[1]);

	if(!map)
	{
		ft_putstr_fd("Error: map is not valid\n",2);
		return (EXIT_FAILURE);
	}

	init_game(game, map);

	while (game->running)
	{
		handle_input_loop(game);
		render_game(game);
	}

	cleanup_game(game);

	return (EXIT_SUCCESS);
}

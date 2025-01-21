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

	load_map(game->map, map_file);		   // Load and validate map
	load_sprites(game->mlx, game->sprites); // Load textures
	init_player(game->player, game->map);   // Initialize player's position
	game->move_count = 0;
	game->running = true;
}





bool	is_valid_file(char *map_file)
{
	const char	*extension;
	int	file_name_len;

	if (!map_file)
		return (false);
	file_name_len = ft_strlen(map_file);
	if (file_name_len <= 4)
		return (false);
	extension = ft_strrchr(map_file, '.');
	if (!extension)
		return (false);
	if(ft_strcmp(extension, ".ber") != 0)
		return (false);
	if (extension == map_file)
		return (false);
	return (true);
}

int	fill_map(t_map *map)
{
	int	i;
	int	j;

	if(map->rows < 3)
	{
		//free
		return(EXIT_FAILURE);
	}

	i = 0;
	map->columns = ft_strlen(map->layout[0]);
	while(map->layout[i])
	{
		if(map->columns != ft_strlen(map->layout[i]))
		{
			//free
			return (EXIT_FAILURE);
		}

		map->walls = ft_count_char(map->layout[i], '1');
		map->player = ft_count_char(map->layout[i], 'P');
		map->exit = ft_count_char(map->layout[i], 'E');
		map->collectibles = ft_count_char(map->layout[i], 'C');
		i++;
	}

	if(map->player != 1 || map->exit != 1 || map->collectibles < 1)
	{
		//free
		return(EXIT_FAILURE);
	}
	// FROM HERE - VALIDATE str1 and str last + first and last char

	return(EXIT_SUCCESS);
}

int	fill_layout(char *map_file, t_map *map)
{
	int	fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error: failed to read from fd\n", 2);
		return (EXIT_FAILURE);
	}

	while(map->rows <= MAX_COLUMNS)
	{
		line = get_next_line(fd);
		if(!line)
			break;
		if(line && (map->rows == MAX_COLUMNS))
		{
			ft_putstr_fd("Error: map is too big\n", 2);
			return (EXIT_FAILURE);
		}

		map->layout[map->rows] = ft_strdup(line);
		if(!map->layout[map->rows])
		{
			map->rows--;
			while(map->rows <= 0)
			{
				free(map->layout[map->rows]);
				map->rows--;
			}
			free(map->layout);
		}
		map->rows++;
	}
	map->layout[map->rows] = NULL;
	close(fd);

	if(fill_map(map) == EXIT_FAILURE)
	{
		ft_putstr_fd("Error: _____\n", 2);
		return (EXIT_FAILURE);
	}
	return(EXIT_SUCCESS);
}

int	init_map(char *map_file, t_map *map)
{
	map->columns = 0;
	map->rows = 0;
	map->collectibles = 0;
	map->walls = 0;
	map->player = 0;
	map->exit = 0;
	map->layout = malloc((MAX_ROWS + 1) * sizeof(char *));
	if(!map->layout)
	{
		ft_putstr_fd("Error: failed to read from fd\n", 2);
		return (EXIT_FAILURE);
	}
	if(fill_layout(map_file, map) == EXIT_FAILURE)
	{
		ft_putstr_fd("Error: _____\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

t_map	*load_map(char *map_file)
{
	t_map	*map;

	if(is_valid_file(map_file) == false)
	{
		ft_putstr_fd("Error: invalide file\n", 2);
		return (NULL);
	}

	map = malloc(sizeof(t_map));
	if (!map)
	{
		exit_with_error("Failed to allocate memory for map");
		return (NULL);
	}

	if(init_map(map_file, map) == EXIT_FAILURE)
	{
		free_map(map); // check all
		return (NULL);
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

	map = load_map(av[1]);

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

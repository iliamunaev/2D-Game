#ifndef SO_LONG_H
#define SO_LONG_H


#include <stdbool.h>    // For boolean type
#include <stdio.h>      // For printf, fprintf
#include <stdlib.h>     // For malloc, free, exit
#include <string.h>     // For string functions
#include <MLX42/MLX42.h>
#include "../libs/libft/libft.h"

#define TILE_SIZE 64

// Structs
typedef struct	s_map
{
	char	**layout;       // 2D array representing the map
	int		columns;           // Map width
	int		rows;          // Map height
	int		collectible_count; // Number of collectibles
}	t_map;

typedef struct s_sprites
{
    mlx_texture_t *wall;        // Wall texture
    mlx_texture_t *floor;       // Floor texture
    mlx_texture_t *player;      // Player sprite texture
    mlx_texture_t *collectible; // Collectible sprite texture
    mlx_texture_t *exit;        // Exit sprite texture
} t_sprites;

typedef struct s_player
{
    int x;               // Player's x-coordinate on the map
    int y;               // Player's y-coordinate on the map
    int collected;       // Number of collectibles collected
}	t_player;

typedef struct s_game
{
	mlx_t	*mlx;          // MLX42 instance
	t_map		*map;          // Game map
	t_sprites *sprites;  // Loaded textures
	t_player *player;    // Player state
	int move_count;      // Number of moves made
	bool running;        // Game loop flag
}	t_game;

// Function Prototypes

// Initialization and Setup
void init_game(t_game *game, const char *map_file);
void load_map(t_map *map, const char *file_path);
void load_sprites(mlx_t *mlx, t_sprites *sprites);
void init_player(t_player *player, t_map *map);

// Game Loop and Rendering
void handle_input_loop(t_game *game);
void render_game(t_game *game);
void render_tile(t_game *game, int x, int y);

// Player Movement
void move_player(t_game *game, int dx, int dy);

// Cleanup and Exit
void cleanup_game(t_game *game);

// Utility
void exit_with_error(const char *message);

#endif

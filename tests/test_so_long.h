
#ifndef TEST_SO_LONG_H
#define TEST_SO_LONG_H


#include <stdbool.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#include <MLX42/MLX42.h>
#include "../libs/libft/libft.h"

#define TILE_SIZE 32

#define INIT_ERROR 2
#define INIT_SUCCESS 3


#define PATH_TO_COLLECTIBLE "../sprites/collectible.png"
#define PATH_TO_WALL "../sprites/wall.png"
#define PATH_TO_EXIT "../sprites/collectible.png"
#define PATH_TO_FLOOR "../sprites/floor.png"
#define PATH_TO_PLAYER "../sprites/player.png"


// Structs
typedef struct s_player
{
	int x;			   // Player's x-coordinate on the map
	int y;			   // Player's y-coordinate on the map
	int collected;	   // Number of collectibles collected
}	t_player;

typedef struct	s_sprites
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*player;
	mlx_image_t	*collectible;
	mlx_image_t	*exit;
}	t_sprites;

typedef struct	s_texture
{
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
	mlx_texture_t	*player;
	mlx_texture_t	*collectible;
	mlx_texture_t	*exit;
} 	t_texture;

typedef struct	s_map
{
	char	**layout;	   // 2D array representing the map
	int		columns;		   // Map width
	int		rows;		  // Map height
	int		collectibles; // Number of collectibles
	int		walls;
	int		floor;
	int		player;
	int		exit;
}	t_map;

typedef struct s_monitor
{
	int32_t	index;
	int32_t	*width;
	int32_t	*height;
}	t_monitor;

typedef struct s_game
{
	mlx_t		*mlx;		  // MLX42 instance
	t_map		*map;		  // Game map
	t_sprites	*sprites;  // Loaded textures
	t_player	*player;	// Player state
	int			move_count;	  // Number of moves made
	bool		running;		// Game loop flag
}	t_game;

t_game	*init_game(void);
int	clean_up_game(t_game *game, t_map *map, char *msg, int exit_mark);

#endif

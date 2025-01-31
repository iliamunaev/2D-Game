#ifndef SO_LONG_H
#define SO_LONG_H


#include <stdbool.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h> // delete on production

#include <MLX42/MLX42.h>
#include "../libs/libft/libft.h"
#include <stdio.h> /// for tests

#define MAX_SCREEN_WIDTH 3840
#define MAX_SCREEN_HEIGHT 2144

#define TILE_SIZE 64
#define STEP 5

#define INIT_ERROR	3
#define INIT_SUCCESS 2

#define MAX_COLUMNS (MAX_SCREEN_WIDTH / 64) 
#define MAX_ROWS (MAX_SCREEN_HEIGHT / 64) 

#define PATH_TO_COLLECTIBLE "./sprites/collectible.png"
#define PATH_TO_WALL "./sprites/wall.png"
#define PATH_TO_EXIT "./sprites/exit.png"
#define PATH_TO_FLOOR "./sprites/floor.png"
#define PATH_TO_PLAYER "./sprites/player.png"

typedef struct s_temp_map
{
	char	**layout;
	int		rows; // must more 2
	int		cols; // must more 3
	int		player; // must 1
	int		collects; // must at least 1
	int 	exit;  // must 1
	bool	is_walls; // must surr
	bool	is_exit_availble;   
	bool	is_collects_availble;	
	bool	is_valid;
}	t_temp_map;

typedef struct s_map
{
	char	**map;
	int		rows;
	int		cols;
	int		collects;
}	t_map;

typedef struct	s_sprites
{
	mlx_image_t	*player;
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*collects;
	mlx_image_t	*exit;
}	t_sprites;

typedef struct s_game
{
	mlx_t		*mlx;
	t_map		*map;
	t_sprites	*sprites;
	int 		collects;
	bool		is_exit;
	bool		is_running;
}	t_game;
    
typedef struct s_program
{
	t_temp_map	*temp_map;
	t_map		*map;
	t_game		*game;
}	t_program;



t_map	*load_map(const char *map_file);
t_temp_map	*init_temp_map(const char *map_file);
int	init_map(const char *map_file, t_map *map);
t_map	*fillup_map(t_temp_map *temp_map);
int	init_layout(const char *map_file, t_temp_map *temp_map);

t_sprites	*load_sprites(t_game *game);

t_game	*init_game(t_map *map);
int	render_game(t_game *game, t_sprites *sprites);

void key_handler(void *param);

#endif

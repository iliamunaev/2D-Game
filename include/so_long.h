#ifndef SO_LONG_H
#define SO_LONG_H


#include <stdbool.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h> // delete on production

#include <MLX42/MLX42.h>
#include "../libs/libft/libft.h"

#define MAX_SCREEN_WIDTH 3840
#define MAX_SCREEN_HEIGHT 2144

#define TILE_SIZE 64
#define STEP 4

#define MOVE_DELAY_FRAMES 10

#define INIT_ERROR	3
#define INIT_SUCCESS 2

#define MAX_COLUMNS (MAX_SCREEN_WIDTH / TILE_SIZE)
#define MAX_ROWS (MAX_SCREEN_HEIGHT / TILE_SIZE)

#define AXE_X 0
#define AXE_Y 1

#define COLLECTIBLE 'C'
#define EXIT 'E'
#define PLAYER 'P'


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
	int		collects; // must at least 1
}	t_temp_map;

typedef struct s_map
{
	char	**map;
	int		rows;
	int		cols;
	int		collects;
}	t_map;
/*
typedef struct s_coorinates
{
	int	x;
	int y;
}	t_coorinates;

typedef struct s_position
{
	int	*up_left;
	int *up_right;
	int *down_left;
	int *down_right;
}	t_position;
*/
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
	//t_position	*position;
	int 		collects;
	int			moves;
	bool		is_exit;
}	t_game;

typedef struct s_program
{
	t_temp_map	*temp_map;
	t_map		*map;
	t_game		*game;
}	t_program;



t_map	*init_map(const char *map_file);
t_temp_map	*init_temp_map(const char *map_file);
int	fillup_map(t_map *map, t_temp_map *temp_map);
int	init_layout(const char *map_file, t_temp_map *temp_map);

t_sprites	*load_sprites(t_game *game);
bool	render_sprite(t_game *game, char target, int row, int col);
t_game	*init_game(t_map *map);
int	render_game(t_game *game, t_sprites *sprites);
bool	render_floor(t_game *game, char target);
void	key_handler(mlx_key_data_t keydata, void *param);

bool  is_valid(t_temp_map *temp_map);

void game_loop(void *param);
#endif

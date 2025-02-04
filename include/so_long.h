#ifndef SO_LONG_H
# define SO_LONG_H


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

// #define INIT_ERROR	3
// #define INIT_SUCCESS 2

#define MAX_COLUMNS 60
#define MAX_ROWS 32

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
	int		rows;
	int		cols;
	int		collects;
}	t_temp_map;

typedef struct s_map
{
	char	**map;
	int		rows;
	int		cols;
	int		collects;
}	t_map;

typedef struct s_corner
{
	int	top_left_y;
	int	top_left_x;
	int	top_right_y;
	int	top_right_x;
	int	bottom_left_y;
	int	bottom_left_x;
	int	bottom_right_y;
	int	bottom_right_x;
}	t_corner;

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
	int			moves;
	bool		is_exit;
}	t_game;


t_map		*init_map(const char *map_file);
t_temp_map	*init_temp_map(const char *map_file);
int			fillup_map(t_map *map, t_temp_map *temp_map);
int			init_layout(const char *map_file, t_temp_map *temp_map);
t_sprites	*load_sprites(t_game *game);
bool		render_sprite(t_game *game, char target, int row, int col);
t_game		*init_game(t_map *map);
int			render_game(t_game *game, t_sprites *sprites);
bool		render_floor(t_game *game, char target);
bool  		is_valid(t_temp_map *temp_map);
void 		game_loop(void *param);
void		free_temp_map(t_temp_map *temp_map);
void		free_map(t_map *map);
bool		is_collectable(char collectable);
t_corner	*init_corners(int next_x, int next_y);
void	trim_2d_array(char **arr);
int fillup_temp_map(t_temp_map *temp_map, const char *map_file);

# endif

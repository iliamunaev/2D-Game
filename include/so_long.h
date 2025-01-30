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

#define PATH_TO_COLLECTIBLE "../sprites/collectible.png"
#define PATH_TO_WALL "../sprites/wall.png"
#define PATH_TO_EXIT "../sprites/collectible.png"
#define PATH_TO_GRASS "./sprites/grass.png"
#define PATH_TO_PLAYER "./sprites/player.png"

typedef struct s_map
{
	char	**layout;
	int		rows;
	int		cols;
	int		player;
	int		collectables;
	int 	exit;
	bool	is_surrounded_walls;
	bool	is_exit_availble;
	bool	is_collectebles_availble;	
	bool	is_valid;


}	t_map;

typedef struct	s_sprites
{
	mlx_image_t	*player;
	mlx_image_t	*grass;
	
}	t_sprites;

typedef struct s_game
{
	mlx_t		*mlx;
	t_map		*map;
	t_sprites	*sprites;
	bool		running;
}	t_game;
    




t_game	*init_game();
mlx_image_t	*get_img(t_game *game, const char *path);
bool	load_textures(t_game *game);
bool	render_game(t_game *game);
void run_game(t_game *game);
void key_handler(void *param);



#endif

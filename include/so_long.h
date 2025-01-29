#ifndef SO_LONG_H
#define SO_LONG_H


#include <stdbool.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h> // delete on production

#include <MLX42/MLX42.h>
#include "../libs/libft/libft.h"
#include <stdio.h> /// for tests

#define MAX_SCREEN_WIDTH 700 //3840
#define MAX_SCREEN_HEIGHT 500 //2144

#define SPRITE_SIZE 64
#define STEP 5

#define MAX_COLUMNS (MAX_SCREEN_WIDTH / 64) 
#define MAX_ROWS (MAX_SCREEN_HEIGHT / 64) 

#define PATH_TO_COLLECTIBLE "../sprites/collectible.png"
#define PATH_TO_WALL "../sprites/wall.png"
#define PATH_TO_EXIT "../sprites/collectible.png"
#define PATH_TO_GRASS "./sprites/grass.png"
#define PATH_TO_PLAYER "./sprites/player.png"


typedef struct	s_sprites
{
	mlx_image_t	*player;
	mlx_image_t	*grass;
	
}	t_sprites;

typedef struct s_game
{
	mlx_t		*mlx;
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

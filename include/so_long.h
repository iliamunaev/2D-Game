/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:34:02 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/10 17:48:37 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h>

# include <MLX42/MLX42.h>
# include "../libs/libft/libft.h"

# define MAX_SCREEN_WIDTH 3840
# define MAX_SCREEN_HEIGHT 2144

# define TILE_SIZE 64
# define STEP 4

# define MAX_COLUMNS 60
# define MAX_ROWS 32

# define AXE_X 0
# define AXE_Y 1

# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define WALL '1'
# define FLOOR '0'

# define PATH_TO_COLLECTIBLE "./sprites/collectible.png"
# define PATH_TO_WALL "./sprites/wall.png"
# define PATH_TO_EXIT "./sprites/exit.png"
# define PATH_TO_FLOOR "./sprites/floor.png"
# define PATH_TO_PLAYER "./sprites/player.png"

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_start
{
	int	row;
	int	col;
}	t_start;

typedef struct s_temp_map
{
	char	**layout;
	int		rows;
	int		cols;
	int		collects;
	int		exit;
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
	int	tly;
	int	tlx;
	int	try;
	int	trx;
	int	bly;
	int	blx;
	int	bry;
	int	brx;
}	t_corner;

typedef struct s_sprites
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
	int			collects;
	int			moves;
	bool		is_exit;
}	t_game;

// init functions
int			handle_arguments(int ac, char **av, const char **map_file);
int			open_map_file(const char *map_file);
t_game		*init_game(const char *map_file);
t_sprites	*init_sprites(t_game *game);
int			render_game(t_game *game, t_sprites *sprites);
t_map		*init_map(const char *map_file);
t_temp_map	*init_temp_map(const char *map_file);
int			fillup_map(t_map *map, t_temp_map *temp_map);
void		trim_2d_array(char **arr);

// map validation functions
bool		is_valid(t_temp_map *temp_map);
bool		additional_validation(t_temp_map *temp_map);
bool		is_cltbl(char collectable);
void		revert_map(t_temp_map *temp_map);
bool		is_walls(t_temp_map *temp_map);
bool		is_rectangular(t_temp_map *temp_map);
bool		is_in_max_columns(t_temp_map *temp_map);
bool		is_valid_chars(t_temp_map *temp_map);
bool		check_exit(t_game *game, char **target, t_corner *corner);
void		check_collectibles(t_game *game, char **target, t_corner *corner);

// path validation functions
bool		check_path_not_null(const char *map_file);
bool		check_filename_length(int file_name_len);
bool		check_extension_ber(const char *map_file, int file_name_len);
bool		check_invalid_chars(const char *map_file, int file_name_len);
bool		check_file_exists(const char *map_file);

// game running functions
void		game_loop(void *param);
void		init_corners(t_corner *corner, int next_x, int next_y);
void		move_player(t_game *game, int nx, int ny);
int			find_collectible_instance(t_game *game, int x, int y);
void		get_collectable(t_game *game, int y, int x);

// free memory functions
void		cleanup(t_game *game, t_sprites *sprites);
void		free_map(t_map *map);
void		free_temp_map(t_temp_map *temp_map);

#endif


# 2D Game: So_long

## Overview

So_long is a basic 2D game using MLX42 library. The goal is to collect all collectibles and reach the exit while avoiding obstacles. Movement and interaction are restricted to predefined map constraints.

### Mandatory Features

- Collect all collectibles before exiting.

- Move with W, A, S, D or/and arrow keys/ZQSD.

- Cannot move through walls.

- Display move count in the terminal.


### Graphics

- Smooth window interactions (minimization, focus change).

- ESC or window close button exits the game.

### Map Rules / Validaion

- Valid elements: Walls (1), Collectibles (C), Empty (0), Exit (E), Player (P).

- Must be rectangular and enclosed by walls.

- Must contain one exit, at least one collectible, and a player start.

- Checks for a valid path.

- Errors result in a clean exit.

- "Corner-Based Radar System"

## Corner-Based Radar System

Corner-Based Radar System ensures accurate collision detection, prevents movement through walls, improves game physics by enforcing tile-based positioning.

The init_corners() function ensures precise movement detection by calculating tile-based corner positions:
```c
void init_corners(t_corner *corner, int next_x, int next_y)
{
    corner->tlx = next_x / TILE_SIZE;
    corner->tly = next_y / TILE_SIZE;
    corner->trx = (next_x + TILE_SIZE - 1) / TILE_SIZE;
    corner->try = next_y / TILE_SIZE;
    corner->blx = next_x / TILE_SIZE;
    corner->bly = (next_y + TILE_SIZE - 1) / TILE_SIZE;
    corner->brx = (next_x + TILE_SIZE - 1) / TILE_SIZE;
    corner->bry = (next_y + TILE_SIZE - 1) / TILE_SIZE;
}
```

## Installation & Execution
```bash
git clone https://github.com/iliamunaev/2D-Game.git && cd 2D-Game	# Clone the repo and change dir
```
```bash
make	# Compile the game
```
Choos map from maps/ directory
```bash
./so_long maps/normal_map.ber  # Run the game
```
Clean the game
```bash
make clean    # Remove compiled files
make fclean   # Full cleanup
make re       # Recompile
```
## Memory leaks checkers
```bash
valgrind --leak-check=full --track-origins=yes --suppressions=valgrind.supp ./so_long maps/map_correct.ber	#with suppression file
```
```bash
valgrind --suppressions=valgrind.supp ./so_long maps/normal_map.ber	#with suppression file
```
```bash
valgrind --leak-check=full --track-origins=yes ./so_long maps/normal_map.ber	#without suppression file
```
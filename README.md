
get screen dimentions

``` bash
xdpyinfo | grep dimensions
```


valgrind --leak-check=full --track-origins=yes --suppressions=mlx42.supp ./so_long maps/map_correct.ber
valgrind --suppressions=mlx42.supp ./so_long maps/map_correct.ber

valgrind --leak-check=full --suppressions=empty.supp ./so_long maps/map_correct.ber
valgrind --leak-check=full --track-origins=yes ./so_long maps/map_correct.ber

grep -nr "strncmp(" . 
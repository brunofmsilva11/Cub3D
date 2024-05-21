#ifndef test_H
# define test_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <signal.h>
# include <sys/stat.h>
# define HEIGHT 840
# define WIDTH 1920
# define WALL 0xffffff
# define FLOOR 0x000000
# define GRID 0x838589
# define PLAYER 0xfffb00
# define SIZE 50
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define FOV 1.0472 // 60 graus em radianos

void    draw_square(void *mlx_ptr, void *win_ptr, int x, int y, int size, int color);


#endif
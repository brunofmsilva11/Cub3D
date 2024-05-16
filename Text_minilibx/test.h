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


typedef struct s_ray
{
    double ray_angle;
    double distance_to_wall;
} t_ray;

typedef struct s_image
{
    void *img;
    char *addr;
    int line_length;
    int bpp;
} t_image;

typedef struct s_dir
{
    void *mlx_ptr;
    void *win_ptr;
    int fd;
    int width;
    int height;
    int key_press_up;
    int key_press_left;
    int key_press_down;
    int key_press_right;
    int key_press_r_left;
    int key_press_r_right;
} t_dir;

typedef struct s_player
{
    double x;
    double y;
    //double angle;
} t_player;

void    draw_square(t_dir *d, int x, int y, int size, int color);
void	my_mlx_pixel_put(t_dir *data, int x, int y, int color);

#endif
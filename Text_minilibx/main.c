#include "test.h"

typedef struct s_ray
{
    double ray_angle;
    double distance_to_wall;
} t_ray;

typedef struct s_dir
{
    void *mlx_ptr;
    void *win_ptr;
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

void draw_rectangle(void *mlx_ptr, void *win_ptr, int x, int y, int width, int height, int color)
{
    int i;
    int j;

    i = x;
    while (i < x + width)
    {
        j = y;
        while (j < y + height)
        {
            mlx_pixel_put(mlx_ptr, win_ptr, i, j, color);
            j++;
        }
        i++;
    }
}

void cast_ray(t_ray *ray, t_player player)
{
    (void)player;
    // Simplesmente definindo uma distância fixa para a parede
    ray->distance_to_wall = 200.0;
}

void draw_walls(void *mlx_ptr, void *win_ptr, t_player player)
{
    t_ray ray;
    int wall_height;

    for (int x = 0; x < WIDTH; x++)
    {
        // Calcular o ângulo do raio para esta coluna
        //double ray_angle = player.angle - atan2(x - WIDTH / 2, WIDTH / 2 / tan(FOV / 2));

        // Lançar o raio e calcular a distância até a parede
        cast_ray(&ray, player);

        // Calcular a altura da parede
        wall_height = (int)(HEIGHT / ray.distance_to_wall);

        // Desenhar a parede
        draw_rectangle(mlx_ptr, win_ptr, x, HEIGHT / 2 - wall_height / 2, 1, wall_height, 0xFFFFFF);
    }
}

t_dir *ft_init()
{
    t_dir *dir;

    dir = malloc(sizeof(t_dir));
    dir->width = 20;
    dir->height = 20;
    dir->key_press_up = 0;
    dir->key_press_left = 0;
    dir->key_press_down = 0;
    dir->key_press_right = 0;
    dir->key_press_r_left = 0;
    dir->key_press_r_right = 0;
    return (dir);
}

int    ft_exit_x()
{
    exit(0);
}
void    game(t_dir *dir)
{
    if(dir->key_press_up && dir->height > 0)
    {
        mlx_clear_window(dir->mlx_ptr, dir->win_ptr);
        draw_square(dir->mlx_ptr, dir->win_ptr, dir->width, dir->height -= 20, 20, 0xFFFFFF);
        dir->key_press_up = 0;
    }
    if(dir->key_press_down && dir->height < 820)
    {
        mlx_clear_window(dir->mlx_ptr, dir->win_ptr);
        draw_square(dir->mlx_ptr, dir->win_ptr, dir->width, dir->height += 20, 20, 0xFFFFFF);
        dir->key_press_down = 0;
    }
    if(dir->key_press_left && dir->width > 0)
    {
        mlx_clear_window(dir->mlx_ptr, dir->win_ptr);
        draw_square(dir->mlx_ptr, dir->win_ptr, dir->width -= 20, dir->height, 20, 0xFFFFFF);
        dir->key_press_left = 0;
    }
    if(dir->key_press_right && dir->width < 1900)
    {
        mlx_clear_window(dir->mlx_ptr, dir->win_ptr);
        draw_square(dir->mlx_ptr, dir->win_ptr, dir->width += 20, dir->height, 20, 0xFFFFFF);
        dir->key_press_right = 0;
    }
}

int	handle_input(int keysym, t_dir *dir)
{
	if (keysym == 65307)
		exit (2);
	if (keysym == 119)
		dir->key_press_up = 1;
	if (keysym == 97)
		dir->key_press_left = 1;
	if (keysym == 115)
		dir->key_press_down = 1;
	if (keysym == 100)
		dir->key_press_right = 1;
	if (keysym == 65361)
		dir->key_press_r_left = 1;
	if (keysym == 65363)
		dir->key_press_r_right = 1;
    game(dir);
	return (0);
}

void    draw_square(void *mlx_ptr, void *win_ptr, int x, int y, int size, int color)
{
    int i;
    int j;

    i = x;
    while(i < x + size)
    {
        j = y;
        while (j < y + size)
        {
            mlx_pixel_put(mlx_ptr, win_ptr, i, j, color);
            j++;
        }
        i++;
    }
}

int main(void)
{
    t_dir *dir;

    //dir = malloc(sizeof(t_dir));
    dir = ft_init();
    dir->mlx_ptr = mlx_init();
    dir->win_ptr = mlx_new_window(dir->mlx_ptr, WIDTH, HEIGHT, "Raycasting Demo");
    draw_square(dir->mlx_ptr, dir->win_ptr, dir->width, dir->height, 20, 0xFFFFFF);
    // Posição inicial do jogador e ângulo de visão
    /* player.x = WIDTH / 2;
    player.y = HEIGHT / 2; */
    //player.angle = 0;

    // Desenhar as paredes
    //draw_walls(mlx_ptr, win_ptr, player);

    mlx_hook(dir->win_ptr, KeyPress, KeyPressMask, handle_input, dir);
    mlx_hook(dir->win_ptr, DestroyNotify, ButtonPressMask, ft_exit_x, dir->mlx_ptr);
    mlx_loop(dir->mlx_ptr);
    return 0;
}

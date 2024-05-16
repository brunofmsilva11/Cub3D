#include "test.h"

t_dir *ft_init()
{
    t_dir *dir;

    dir = malloc(sizeof(t_dir));
    dir->width = 20;
    dir->height = 20;
    dir->fd = 0;
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
        draw_square(dir, dir->width, dir->height -= 20, 20, 0xFFFFFF);
        dir->key_press_up = 0;
    }
    if(dir->key_press_down && dir->height < 820)
    {
        mlx_clear_window(dir->mlx_ptr, dir->win_ptr);
        draw_square(dir, dir->width, dir->height += 20, 20, 0xFFFFFF);
        dir->key_press_down = 0;
    }
    if(dir->key_press_left && dir->width > 0)
    {
        mlx_clear_window(dir->mlx_ptr, dir->win_ptr);
        draw_square(dir, dir->width -= 20, dir->height, 20, 0xFFFFFF);
        dir->key_press_left = 0;
    }
    if(dir->key_press_right && dir->width < 1900)
    {
        mlx_clear_window(dir->mlx_ptr, dir->win_ptr);
        draw_square(dir, dir->width += 20, dir->height, 20, 0xFFFFFF);
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

void draw_square(t_dir *d, int x, int y, int size, int color)
{
    int i, j;
    i = x;
    j = y;
    //int *image_buffer = (int *)malloc(size * size * sizeof(int));

    // Fill the image buffer with pixel colors
    int index = 0;
    /* for (i = x; i < x + size; i++)
    {
        for (j = y; j < y + size; j++)
        {
            image_buffer[index] = color;
            index++;
        }
    } */

    // Create a new image in memory
    void *img_ptr = mlx_new_image(d->mlx_ptr, size, size);
    int bits_per_pixel;
    int size_line;
    int endian;
    int *img_data = (int *)mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);

    while(i < x + size)
    {
        j = y;
        while(j < y + size)
        {
            img_data[index] = color;
            index++;
            j++;
        }
        i++;
    }

    // Copy the pixel data from the image buffer to the image
    /* for (index = 0; index < size * size; index++)
    {
        img_data[index] = image_buffer[index];
    } */

    // Display the image on the window
    mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, img_ptr, x, y);
    //mlx_destroy_image(d->mlx_ptr, img_ptr); // Clean up the image

    //mlx_do_sync(d->mlx_ptr); // Ensure all changes are applied before displaying

    //free(image_buffer);
}




/* void    draw_square(t_dir *d, int x, int y, int size, int color)
{
    int i;
    int j;

    i = x;
    while(i < x + size)
    {
        j = y;
        while (j < y + size)
        {
            mlx_pixel_put(d->mlx_ptr, d->win_ptr, i, j, color);
            //my_mlx_pixel_put(d, x, y, color);
            j++;
        }
        i++;
    }
} */

void    draw_map(t_dir *d, char *file_name, int size, int color)
{
    int i;
    char *line;
    int x;
    int y;

    i = 0;
    x = 0;
    y = 0;
    d->fd = open(file_name, O_RDONLY);
    line = get_next_line(d->fd);
    while(line)
    {
        i = 0;
        x = 0;
        while(line[i])
        {
            if(line[i] == '1')
            {
                draw_square(d, x, y, size, color);
                x += 100;
            }
            else if(line[i] == '0')
                x += 100;
            else if(line[i] == '\n')
                y += 100;
            else
            {
                draw_square(d, x, y, size, 0xFF9200);
                x += 100;
            }
            i++;
        }
        free(line);
        line = get_next_line(d->fd);
    }
    close(d->fd);
}

int main(int ac, char **av)
{
    t_dir *dir;

    (void)ac;
    dir = ft_init();
    dir->mlx_ptr = mlx_init();
    dir->win_ptr = mlx_new_window(dir->mlx_ptr, WIDTH, HEIGHT, "Raycasting Demo");
    draw_map(dir, av[1], 100, 0x1515D6);
    //draw_square(dir->mlx_ptr, dir->win_ptr, dir->width, dir->height, 20, 0xFFFFFF);
    mlx_hook(dir->win_ptr, KeyPress, KeyPressMask, handle_input, dir);
    mlx_hook(dir->win_ptr, DestroyNotify, ButtonPressMask, ft_exit_x, dir->mlx_ptr);
    mlx_loop(dir->mlx_ptr);
    return 0;
}

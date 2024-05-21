#include "test.h"

t_dir *ft_init()
{
    t_dir *dir;

    dir = malloc(sizeof(t_dir));
    dir->width = 100;
    dir->height = 100;
    dir->fd = 0;
    dir->key_press_up = 0;
    dir->key_press_left = 0;
    dir->key_press_down = 0;
    dir->key_press_right = 0;
    dir->key_press_r_left = 0;
    dir->key_press_r_right = 0;
    dir->file_name = 0;
    dir->size = 100;
    dir->p_color = 0xFF9200;
    dir->w_color = 0x1515D6;

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
        //mlx_clear_window(dir->mlx_ptr, dir->win_ptr);
        draw_arrow_N(dir);
        dir->key_press_up = 0;
    }
    if(dir->key_press_down && dir->height < 820)
    {
        //mlx_clear_window(dir->mlx_ptr, dir->win_ptr);
        draw_arrow_S(dir);
        dir->key_press_down = 0;
    }
    if(dir->key_press_left && dir->width > 0)
    {
        //mlx_clear_window(dir->mlx_ptr, dir->win_ptr);
        draw_arrow_W(dir);
        dir->key_press_left = 0;
    }
    if(dir->key_press_right && dir->width < 1900)
    {
        //mlx_clear_window(dir->mlx_ptr, dir->win_ptr);
        draw_arrow_E(dir);
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

void draw_square(t_dir *d)
{
    int i, j;
    i = d->width;
    j = d->height;
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
    void *img_ptr = mlx_new_image(d->mlx_ptr, d->size, d->size);
    int bits_per_pixel;
    int size_line;
    int endian;
    int *img_data = (int *)mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);

    while(i < d->width + d->size)
    {
        j = d->height;
        while(j < d->height + d->size)
        {
            img_data[index] = d->w_color;
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
    mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, img_ptr, d->width, d->height);
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

void    draw_map(t_dir *d)
{
    int i;
    char *line;

    i = 0;
    d->fd = open(d->file_name, O_RDONLY);
    line = get_next_line(d->fd);
    while(line)
    {
        i = 0;
        d->width = 0;
        while(line[i])
        {
            if(line[i] == '1')
            {
                draw_square(d);
                d->width += 100;
            }
            else if(line[i] == '0')
                d->width += 100;
            else if(line[i] == '\n')
                d->height += 100;
            else
            {
                d->p_x = d->width;
                d->p_y = d->height;
                if(line[i] == 'N')
                {
                    draw_arrow_N(d);
                    d->width += 100;
                }
                else if(line[i] == 'S')
                {
                    draw_arrow_S(d);
                    d->width += 100;
                }
                else if(line[i] == 'E')
                {
                    draw_arrow_E(d);
                    d->width += 100;
                }
                else if(line[i] == 'W')
                {
                    draw_arrow_W(d);
                    d->width += 100;
                }
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
    dir->file_name = ft_strdup(av[1]);
    dir->win_ptr = mlx_new_window(dir->mlx_ptr, WIDTH, HEIGHT, "Raycasting Demo");
    draw_map(dir);
    //draw_square(dir->mlx_ptr, dir->win_ptr, dir->width, dir->height, 20, 0xFFFFFF);
    mlx_hook(dir->win_ptr, KeyPress, KeyPressMask, handle_input, dir);
    mlx_hook(dir->win_ptr, DestroyNotify, ButtonPressMask, ft_exit_x, dir->mlx_ptr);
    mlx_loop(dir->mlx_ptr);
    return 0;
}

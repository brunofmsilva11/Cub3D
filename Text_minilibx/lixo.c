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

/* void	my_mlx_pixel_put(t_dir *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img->addr + (y * data->img->line_length
			+ x * (data->img->bpp / 8));
	*(unsigned int *)dst = color;
} */
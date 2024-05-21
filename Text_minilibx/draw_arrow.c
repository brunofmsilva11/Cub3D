#include "test.h"

void    draw_arrow_N(t_dir *d)
{
    int i;

    // Draw vertical line
    for (i = 0; i < d->size; i++) {
        mlx_pixel_put(d->mlx_ptr, d->win_ptr, (d->p_x + d->size / 2), d->p_y + i, d->p_color);
    }

    // Draw left diagonal line
    for (i = 0; i < d->size / 2; i++) {
        mlx_pixel_put(d->mlx_ptr, d->win_ptr, (d->p_x + d->size / 2 - i), d->p_y + i, d->p_color);
    }

    // Draw right diagonal line
    for (i = 0; i < d->size / 2; i++) {
        mlx_pixel_put(d->mlx_ptr, d->win_ptr, (d->p_x + d->size / 2 + i), d->p_y + i, d->p_color);
    }
}

void    draw_arrow_S(t_dir *d)
{
    int i;

    // Draw vertical line
    for (i = 0; i < d->size; i++) {
        mlx_pixel_put(d->mlx_ptr, d->win_ptr, d->p_x + d->size / 2, d->p_y + i, d->p_color);
    }

    // Draw left diagonal line
    for (i = 0; i < d->size / 2; i++) {
        mlx_pixel_put(d->mlx_ptr, d->win_ptr, d->p_x + d->size / 2 - i, d->p_y + i, d->p_color);
    }

    // Draw right diagonal line
    for (i = 0; i < d->size / 2; i++) {
        mlx_pixel_put(d->mlx_ptr, d->win_ptr, d->p_x + d->size / 2 - i, d->p_y + i, d->p_color);
    }
}

void    draw_arrow_W(t_dir *d)
{
    int i;

    // Draw horizontal line
    for (i = 0; i < d->size; i++) {
        mlx_pixel_put(d->mlx_ptr, d->win_ptr, d->p_x + i, (d->p_y + d->size / 2), d->p_color);
    }

    // Draw up diagonal line
    for (i = 0; i < d->size / 2; i++) {
        mlx_pixel_put(d->mlx_ptr, d->win_ptr, d->p_x + i, d->p_y + d->size / 2 - i, d->p_color);
    }

    // Draw down diagonal line
    for (i = 0; i < d->size / 2; i++) {
        mlx_pixel_put(d->mlx_ptr, d->win_ptr, d->p_x + i, d->p_y + d->size / 2 + i, d->p_color);
    }
}

void    draw_arrow_E(t_dir *d)
{
    int i;

    // Draw horizontal line
    for (i = 0; i < d->size; i++) {
        mlx_pixel_put(d->mlx_ptr, d->win_ptr, d->p_x + i, d->p_y + d->size / 2, d->p_color);
    }

    // Draw up diagonal line
    for (i = 0; i < d->size / 2; i++) {
        mlx_pixel_put(d->mlx_ptr, d->win_ptr, d->p_x + d->size - i, d->p_y + d->size / 2 - i, d->p_color);
    }

    // Draw down diagonal line
    for (i = 0; i < d->size / 2; i++) {
        mlx_pixel_put(d->mlx_ptr, d->win_ptr, d->p_x + d->size - i, d->p_y + d->size / 2 + i, d->p_color);
    }
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:21:10 by bmota-si          #+#    #+#             */
/*   Updated: 2024/06/05 16:37:56 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	get_hit(t_data *d)
{
	while (!d->hit)
	{
		if (d->side_dist_x < d->side_dist_y)
		{
			d->side_dist_x += d->delta_dist_x;
			d->mapx += d->stepx;
			d->side = 0;
		}
		else
		{
			d->side_dist_y += d->delta_dist_y;
			d->mapy += d->stepy;
			d->side = 1;
		}
		if (d->map_utils->map[d->mapy][d->mapx] == '1')
			d->hit = 1;
	}
}

void	check_side(t_data *d)
{
	if (d->raydir_x < 0)
	{
		d->stepx = -1;
		d->side_dist_x = (d->p_x - d->mapx) * d->delta_dist_x;
	}
	else
	{
		d->stepx = 1;
		d->side_dist_x = (d->mapx + 1.0 - d->p_x) * d->delta_dist_x;
	}
	if (d->raydir_y < 0)
	{
		d->stepy = -1;
		d->side_dist_y = (d->p_y - d->mapy) * d->delta_dist_y;
	}
	else
	{
		d->stepy = 1;
		d->side_dist_y = (d->mapy + 1.0 - d->p_y) * d->delta_dist_y;
	}
}

void	ray_calc(t_data *d)
{
	d->camera_x = 2 * d->i / (double)WIDTH - 1;
	d->raydir_x = d->dir_x + d->plane_x * d->camera_x;
	d->raydir_y = d->dir_y + d->plane_y * d->camera_x;
	d->mapx = (int)d->p_x;
	d->mapy = (int)d->p_y;
	if (d->raydir_x == 0)
		d->delta_dist_x = 1e30;
	else
		d->delta_dist_x = fabs(1 / d->raydir_x);
	if (d->raydir_y == 0)
		d->delta_dist_y = 1e30;
	else
		d->delta_dist_y = fabs(1 / d->raydir_y);
	d->hit = 0;
}

void	draw_raycast(t_data *d)
{
	put_color_on_window(d);
	d->i = 0;
	while (d->i < WIDTH)
	{
		ray_calc(d);
		check_side(d);
		get_hit(d);
		ray_values(d);
		get_texture_val(d);
		ft_draw(d, d->i);
		d->i++;
	}
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img->img, 0, 0);
}

void	ft_start(t_data *d)
{
	d->mlx_ptr = mlx_init();
	if (d->mlx_ptr == NULL)
		return ;
	init_struct_imgs(d);
	ft_init_stack3(d);
	get_imgs_xpm(d);
	check_imgs_xpm(d);
	d->win_ptr = mlx_new_window(d->mlx_ptr, WIDTH, HEIGHT, "cub3d");
	direction(d);
	draw_raycast(d);
	mlx_hook(d->win_ptr, KeyPress, KeyPressMask, handle_input, d);
	mlx_hook(d->win_ptr, KeyRelease, KeyReleaseMask, release_key, d);
	mlx_hook(d->win_ptr, DestroyNotify, ButtonPressMask, ft_exit_x, d);
	mlx_loop_hook(d->mlx_ptr, game_loop, d);
	mlx_loop(d->mlx_ptr);
}

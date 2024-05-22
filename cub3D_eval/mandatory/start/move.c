/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:24:57 by bmota-si          #+#    #+#             */
/*   Updated: 2024/05/22 13:19:04 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	game_loop(t_data *d)
{
	if (!ft_movs(d))
		return (0);
	mlx_destroy_image(d->mlx_ptr, d->img->img);
	d->img->img = mlx_new_image(d->mlx_ptr, WIDTH, HEIGHT);
	draw_raycast(d);
	return (0);
}

int	ft_movs(t_data *d)
{
	if (d->key_press_up == 1)
		move_vertical(d, 1);
	if (d->key_press_down == 1)
		move_vertical(d, 0);
	if (d->key_press_right == 1)
		move_horizontal(d, 1);
	if (d->key_press_left == 1)
		move_horizontal(d, 0);
	if (d->key_press_r_left == 1)
		rotate_player(d, -1);
	if (d->key_press_r_right == 1)
		rotate_player(d, 1);
	if (d->key_press_up || d->key_press_down || d->key_press_left
		|| d->key_press_right || d->key_press_r_left || d->key_press_r_right)
		return (1);
	return (0);
}

void	move_vertical(t_data *d, int dir_flag)
{
	if (dir_flag)
	{
		if (d->map_utils->map[(int)(d->p_y + d->dir_y * 0.1)]
			[(int) d->p_x] != '1')
			d->p_y += d->dir_y * 0.1;
		if (d->map_utils->map[(int)d->p_y]
			[(int)(d->p_x + d->dir_x * 0.1)] != '1')
			d->p_x += d->dir_x * 0.1;
	}
	else
	{
		if (d->map_utils->map[(int)(d->p_y - d->dir_y * 0.1)]
			[(int) d->p_x] != '1')
			d->p_y -= d->dir_y * 0.1;
		if (d->map_utils->map[(int)d->p_y]
			[(int)(d->p_x - d->dir_x * 0.1)] != '1')
			d->p_x -= d->dir_x * 0.1;
	}
}

void	move_horizontal(t_data *d, int dir_flag)
{
	if (dir_flag)
	{
		if (d->map_utils->map[(int)(d->p_y + d->dir_x * 0.1)]
			[(int) d->p_x] != '1')
			d->p_y += d->dir_x * 0.1;
		if (d->map_utils->map[(int)d->p_y]
			[(int)(d->p_x - d->dir_y * 0.1)] != '1')
			d->p_x -= d->dir_y * 0.1;
	}
	else
	{
		if (d->map_utils->map[(int)(d->p_y - d->dir_x * 0.1)]
			[(int) d->p_x] != '1')
			d->p_y -= d->dir_x * 0.1;
		if (d->map_utils->map[(int)d->p_y]
			[(int)(d->p_x + d->dir_y * 0.1)] != '1')
			d->p_x += d->dir_y * 0.1;
	}
}

void	rotate_player(t_data *d, int dir_flag)
{
	double	angle;
	double	temp_x;
	double	temp_y;

	angle = 0.10;
	if (dir_flag != 1)
		angle *= -1;
	temp_x = d->dir_x * cos(angle) - d->dir_y * sin(angle);
	temp_y = d->dir_x * sin(angle) + d->dir_y * cos(angle);
	d->dir_x = temp_x;
	d->dir_y = temp_y;
	temp_x = d->plane_x * cos(angle) - d->plane_y * sin(angle);
	temp_y = d->plane_x * sin(angle) + d->plane_y * cos(angle);
	d->plane_x = temp_x;
	d->plane_y = temp_y;
}

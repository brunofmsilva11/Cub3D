/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:15:09 by bruno             #+#    #+#             */
/*   Updated: 2024/06/05 14:37:43 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	get_texture_val(t_data *d)
{
	if (d->side == 1)
	{
		if (d->raydir_y < 0)
			d->aux = d->s_img;
		else
			d->aux = d->n_img;
	}
	else
	{
		if (d->raydir_x < 0)
			d->aux = d->e_img;
		else
			d->aux = d->w_img;
	}
}

void	ray_values(t_data *d)
{
	if (d->side == 0)
		d->perp_wall_dist = (d->side_dist_x - d->delta_dist_x);
	else
		d->perp_wall_dist = (d->side_dist_y - d->delta_dist_y);
	if (d->perp_wall_dist)
		d->line_height = (int)(HEIGHT / d->perp_wall_dist);
	else
		d->line_height = HEIGHT;
	d->draw_start = -d->line_height / 2 + HEIGHT / 2;
	if (d->draw_start < 0)
		d->draw_start = 0;
	d->draw_end = d->line_height / 2 + HEIGHT / 2;
	if (d->draw_end >= HEIGHT)
		d->draw_end = HEIGHT - 1;
}

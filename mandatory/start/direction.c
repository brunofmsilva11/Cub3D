/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:08:07 by bmota-si          #+#    #+#             */
/*   Updated: 2024/05/31 14:19:25 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	direction(t_data *d)
{
	if (d->map_utils->player_pos == 'N')
	{
		d->dir_x = 0;
		d->dir_y = -1;
		d->plane_x = 0.66;
		d->plane_y = 0;
		return ;
	}
	if (d->map_utils->player_pos == 'S')
	{
		d->dir_x = 0;
		d->dir_y = 1;
		d->plane_x = -0.66;
		d->plane_y = 0;
		return ;
	}
	direction2(d);
}

void	direction2(t_data *d)
{
	if (d->map_utils->player_pos == 'E')
	{
		d->dir_x = 1;
		d->dir_y = 0;
		d->plane_x = 0;
		d->plane_y = 0.66;
		return ;
	}
	if (d->map_utils->player_pos == 'W')
	{
		d->dir_x = -1;
		d->dir_y = 0;
		d->plane_x = 0;
		d->plane_y = -0.66;
		return ;
	}
}

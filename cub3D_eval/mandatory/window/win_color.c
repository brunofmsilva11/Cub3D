/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:57:10 by bmota-si          #+#    #+#             */
/*   Updated: 2024/05/22 13:34:11 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	put_color_on_window(t_data *d)
{
	unsigned int	f_color;
	unsigned int	c_color;

	f_color = (0x010000 * ft_atoi(d->map_utils->f_color[0])) + (0x000100
			* ft_atoi(d->map_utils->f_color[1]))
		+ ft_atoi(d->map_utils->f_color[2]);
	c_color = 0x010000 * ft_atoi(d->map_utils->c_color[0]) + 0x000100
		* ft_atoi(d->map_utils->c_color[1])
		+ ft_atoi(d->map_utils->c_color[2]);
	put_color_on_window2(d, f_color, c_color);
}

void	put_color_on_window2(t_data *d, int f_color, int c_color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (y <= (HEIGHT / 2))
				my_mlx_pixel_put(d, x, y, c_color);
			if (y > (HEIGHT / 2))
				my_mlx_pixel_put(d, x, y, f_color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img->img, 0, 0);
}

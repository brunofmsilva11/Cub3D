/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:31:30 by bmota-si          #+#    #+#             */
/*   Updated: 2024/06/05 14:37:43 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	get_imgs_xpm(t_data *d)
{
	d->img->img = mlx_new_image(d->mlx_ptr, WIDTH, HEIGHT);
	d->n_img->img = mlx_xpm_file_to_image(d->mlx_ptr, d->map_utils->no,
			&d->n_img->w, &d->n_img->h);
	d->s_img->img = mlx_xpm_file_to_image(d->mlx_ptr, d->map_utils->so,
			&d->s_img->w, &d->s_img->h);
	d->w_img->img = mlx_xpm_file_to_image(d->mlx_ptr, d->map_utils->we,
			&d->w_img->w, &d->w_img->h);
	d->e_img->img = mlx_xpm_file_to_image(d->mlx_ptr, d->map_utils->ea,
			&d->e_img->w, &d->e_img->h);
	if (!d->img->img || !d->n_img->img || !d->s_img->img
		|| !d->w_img->img || !d->e_img->img)
	{
		ft_free_data(d);
		finish_error("Error\nInvalid texture file\n", 2);
		return ;
	}
	get_imgs_addr(d);
}

void	get_imgs_addr(t_data *d)
{
	d->img->addr = mlx_get_data_addr(d->img->img, &d->img->bpp,
			&d->img->line_length, &d->img->endian);
	d->n_img->addr = mlx_get_data_addr(d->n_img->img, &d->n_img->bpp,
			&d->n_img->line_length, &d->n_img->endian);
	d->s_img->addr = mlx_get_data_addr(d->s_img->img, &d->s_img->bpp,
			&d->s_img->line_length, &d->s_img->endian);
	d->w_img->addr = mlx_get_data_addr(d->w_img->img, &d->w_img->bpp,
			&d->w_img->line_length, &d->w_img->endian);
	d->e_img->addr = mlx_get_data_addr(d->e_img->img, &d->e_img->bpp,
			&d->e_img->line_length, &d->e_img->endian);
}

void	check_imgs_xpm(t_data *d)
{
	if (d->n_img->line_length != 256
		|| d->s_img->line_length != 256
		|| d->w_img->line_length != 256
		|| d->e_img->line_length != 256)
	{
		ft_free_data(d);
		finish_error("Error\nInvalid size image!\n", 2);
	}
}

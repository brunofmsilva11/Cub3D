/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:59:34 by bmota-si          #+#    #+#             */
/*   Updated: 2024/05/22 13:15:22 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	error_dup_elem(t_data *d, char *line, int n)
{
	ft_no_leak(d, line);
	free(line);
	ft_free_data2(d);
	if (n == 10)
		finish_error("Error: The number of player different 1!\n", 2);
	else if (n == 11)
		finish_error("Error: Letters wrong or not followed by a space!\n", 2);
	else if (n == 12)
		finish_error("Error: Empty line inside the map!\n", 2);
	else if (n == 13)
		finish_error("Error: Invalid character in empty line!\n", 2);
	else if (n == 14)
		finish_error("Error: Invalid character in map!\n", 2);
	else if (n == 15)
		finish_error("Error: Player can't move!\n", 2);
	else
		finish_error("Error2: invalid elements!\n", 2);
}

void	no_tab_error_handle(t_data *d)
{
	close(d->fd);
	close(d->temp_fd);
	ft_no_leak(d, d->line);
	free(d->line);
	ft_free_data2(d);
	finish_error("Error\nProgram does not suport tabs\n", 2);
}
void	error_textures(t_data *d, char *str)
{
	ft_free_data4(d);
	finish_error(str, 2);
}

void	ft_free_data4(t_data *d)
{
	if (d->map_utils->flag_c)
		ft_free_str_array(&d->map_utils->c_color);
	if (d->map_utils->flag_f)
		ft_free_str_array(&d->map_utils->f_color);
	if (d->map_utils->map)
		ft_free_str_array(&d->map_utils->map);
	if (d->map_utils->map_dup)
		ft_free_str_array(&d->map_utils->map_dup);
	if (d->map_utils->color_aux)
		ft_free_str_array(&d->map_utils->color_aux);
	if (d->map_utils->ea)
		free(d->map_utils->ea);
	if (d->map_utils->no)
		free(d->map_utils->no);
	if (d->map_utils->so)
		free(d->map_utils->so);
	if (d->map_utils->we)
		free(d->map_utils->we);
	ft_free_data5(d);
	free(d->map_utils);
	if (d->win_ptr)
		mlx_destroy_window(d->mlx_ptr, d->win_ptr);
	mlx_destroy_display(d->mlx_ptr);
	free(d->mlx_ptr);
	free(d);
}

void	ft_free_data5(t_data *d)
{
	free(d->n_img);
	free(d->s_img);
	free(d->w_img);
	free(d->e_img);
	free(d->img);
}

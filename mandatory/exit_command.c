/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:09:28 by bmota-si          #+#    #+#             */
/*   Updated: 2024/06/05 14:37:43 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	ft_exit_x(t_data *d)
{
	if (d != NULL && d->mlx_ptr != NULL && d->win_ptr != NULL)
		ft_free_data(d);
	exit(0);
}

int	release_key(int keysym, t_data *d)
{
	if (keysym == 119)
		d->key_press_up = 0;
	if (keysym == 97)
		d->key_press_left = 0;
	if (keysym == 115)
		d->key_press_down = 0;
	if (keysym == 100)
		d->key_press_right = 0;
	if (keysym == 65361)
		d->key_press_r_left = 0;
	if (keysym == 65363)
		d->key_press_r_right = 0;
	return (0);
}

int	handle_input(int keysym, t_data *d)
{
	(void) d;
	if (keysym == 65307)
	{
		ft_free_data(d);
		exit (2);
	}
	if (keysym == 119)
		d->key_press_up = 1;
	if (keysym == 97)
		d->key_press_left = 1;
	if (keysym == 115)
		d->key_press_down = 1;
	if (keysym == 100)
		d->key_press_right = 1;
	if (keysym == 65361)
		d->key_press_r_left = 1;
	if (keysym == 65363)
		d->key_press_r_right = 1;
	return (0);
}

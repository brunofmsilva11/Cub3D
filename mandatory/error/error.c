/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:54:37 by bmota-si          #+#    #+#             */
/*   Updated: 2024/06/05 16:37:56 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	finish_error(char *str, int i)
{
	ft_putstr_fd(str, i);
	exit (i);
}

void	file_name_error(t_data *d)
{
	free(d->map_utils);
	free(d);
	finish_error("Error\nInvalid file type\n", 2);
}

void	error_rgb(char *line, t_data *d, char *str)
{
	(void)d;
	ft_no_leak2(d, line);
	free(line);
	ft_free_data2(d);
	finish_error(str, 2);
}

void	error_in_elem(t_data *d, char *line)
{
	ft_no_leak(d, line);
	free(line);
	ft_free_data(d);
	finish_error("Error\nInvalid element!\n", 2);
}

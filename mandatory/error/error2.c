/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:59:34 by bmota-si          #+#    #+#             */
/*   Updated: 2024/05/24 17:56:56 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	error_dup_elem(t_data *d, char *line, int n)
{
	ft_no_leak(d, line);
	free(line);
	ft_free_data7(d);
	if (n == 0)
		finish_error("Error\nThe number of player different 1!\n", 2);
	else if (n == 4)
		finish_error("Error\nMap doesn't exist!\n", 2);
	else if (n == 11)
		finish_error("Error\nWrong initials or not followed by a space!\n", 2);
	else if (n == 12)
		finish_error("Error\nEmpty line inside the map!\n", 2);
	else if (n == 2 || n == 13)
		finish_error("Error\nInvalid character in map!\n", 2);
	else if (n == 3)
		finish_error("Error\nPlayer can't move!\n", 2);
	else if (n == 16)
		finish_error("Error\nMap is not closed!\n", 2);
	else
		finish_error("Error\nInvalid elements!\n", 2);
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

void	error_first_elem(t_data *d, char *line)
{
	ft_no_leak(d, line);
	free(line);
	ft_free_data8(d);
	finish_error("Error\nThe number of player different 1!\n", 2);
}

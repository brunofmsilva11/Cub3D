/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:59:34 by bmota-si          #+#    #+#             */
/*   Updated: 2024/05/08 18:06:00 by bmota-si         ###   ########.fr       */
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

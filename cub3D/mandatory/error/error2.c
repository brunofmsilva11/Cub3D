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

void	error_dup_elem(t_data *d, char *line)
{
	ft_no_leak(d, line);
	free(line);
	ft_free_data2(d);
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

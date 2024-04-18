/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:18:15 by bmota-si          #+#    #+#             */
/*   Updated: 2024/04/17 11:37:25 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	map_validation_test(t_data *d, char *file_name)
{
    char *line;
	int i;
	
    i = 0;
    d->fd = open(file_name, O_RDONLY);
	line = get_next_line(d->fd);
	while (i < 6)
    {
		line = get_next_line(d->fd);
		i++;
	}
    while (1)
	{
		if (line[0] == '\n')
        	line = get_next_line(d->fd);
		else
			break;
	}
	printf("%s", line);
}
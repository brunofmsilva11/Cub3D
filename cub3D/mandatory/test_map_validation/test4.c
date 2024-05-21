/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:37:33 by bruno             #+#    #+#             */
/*   Updated: 2024/05/20 20:38:08 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int is_map_closed(t_data *d)
{
	int i;
	int j;

	i = 0;
	j = 0;
	d->map_utils->skip_count = 0;
	if (!check_first_last(d))
		return (0);
	while(d->map_utils->map[i][j])
	{
		if (!check_value2(d, i, j))
			return (d->error);
		if (d->map_utils->map[i][j] == ' ' || d->map_utils->map[i][j] == '\n')
			if(check_coord(d, i, j, '0') == 0)
					return (0);
		if(d->map_utils->map[i][j] == '\n')
		{
			j = 0;
			i++;
		}
		else
			j++;
	}
	return (1);
}

void skip_lines(t_data *d, int count)
{
    char *line;
    int i;

	line = NULL;
	i = count;
    while (i != 0)
	{
        line = get_next_line(d->fd);
        if (!line)
            break;
        i--;
        free(line);
    }
}

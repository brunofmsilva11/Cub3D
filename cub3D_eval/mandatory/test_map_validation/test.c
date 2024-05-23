/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:18:15 by bmota-si          #+#    #+#             */
/*   Updated: 2024/05/23 12:32:27 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	is_map_closed(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	d->map_utils->skip_count = 0;
	if (!check_first_last(d))
		return (0);
	while (d->map_utils->map[i][j])
	{
		if (check_value2(d, i, j) != 1)
			return (d->error);
		if (d->map_utils->map[i][j] == ' ' || d->map_utils->map[i][j] == '\n')
			if (check_coord(d, i, j, '0') == 0)
				return (16);
		if (d->map_utils->map[i][j] == '\n')
		{
			j = 0;
			i++;
		}
		else
			j++;
	}
	return (1);
}

void	skip_lines(t_data *d, int count)
{
	char	*line;
	int		i;

	line = NULL;
	i = count;
	while (i != 0)
	{
		line = get_next_line(d->fd);
		if (!line)
			break ;
		i--;
		free(line);
	}
}

void	populate_map(t_data *d, int lines_read, char *file_name)
{
	char	*line;

	d->line_height = lines_read;
	d->map_utils->map = malloc(sizeof(char *) * (lines_read + 1));
	close(d->fd);
	d->fd = open(file_name, O_RDONLY);
	skip_lines(d, d->map_utils->skip_count);
	line = get_next_line(d->fd);
	d->map_utils->skip_count = 0;
	while (line)
	{
		if (!line)
			break ;
		if (check_enter(line))
			;
		else
		{
			process_map_line(d, line);
			d->map_utils->skip_count++;
		}
		free(line);
		line = get_next_line(d->fd);
	}
	d->map_utils->map[d->map_utils->skip_count] = "\0";
}

void	map_validation_test(t_data *d, char *file_name)
{
	int	lines_read;
	int	i;

	lines_read = 0;
	i = d->map_utils->skip_count;
	d->fd = open(file_name, O_RDONLY);
	skip_lines(d, i);
	read_map_lines(d, &lines_read);
	populate_map(d, lines_read, file_name);
	d->error = is_map_closed(d);
	d->map_utils->map[lines_read] = NULL;
	close(d->fd);
}

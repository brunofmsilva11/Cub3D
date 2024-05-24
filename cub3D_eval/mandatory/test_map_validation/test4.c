/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:37:33 by bruno             #+#    #+#             */
/*   Updated: 2024/05/24 18:30:21 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	read_map_lines(t_data *d, int *lines_read)
{
	char	*line;
	int		count;

	line = NULL;
	count = 0;
	while (1)
	{
		line = get_next_line(d->fd);
		if (!line)
			break ;
		read_map_lines2(d, line);
		if (d->line_length < (int)ft_strlen(line))
			d->line_length = ft_strlen(line) - 1;
		if (ft_strcmp(line, "\n"))
		{
			//printf("%s", line);
			(*lines_read)++;
			count++;
		}
		free(line);
	}
}

void	read_map_lines2(t_data *d, char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (check_value(line[i]))
			i++;
		else
			error_dup_elem(d, line, 13);
	}
}

void	process_map_line(t_data *d, char *line)
{
	int	i;
	int	j;

	i = d->map_utils->skip_count;
	j = 0;
	if (check_char(line))
	{
		d->map_utils->map[i] = malloc(sizeof(char) * (d->line_length + 2));
		while (j < d->line_length)
		{
			while (line[j] != '\0' && line[j] != '\n')
			{
				d->map_utils->map[i][j] = line[j];
				j++;
			}
			if (j < d->line_length)
				j = put_spaces(d, i, j);
		}
		if (i < d->line_height - 1)
		{
			d->map_utils->map[i][j] = '\n';
			d->map_utils->map[i][j + 1] = '\0';	
		}
		else
			d->map_utils->map[i][j] = '\0';
	}
	else
		error_first_elem(d, line);
}

int	put_spaces(t_data *d, int i, int j)
{
	while (j < d->line_length)
	{
		d->map_utils->map[i][j] = ' ';
		j++;
	}
	return (j);
}

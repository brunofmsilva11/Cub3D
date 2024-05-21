/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:18:15 by bmota-si          #+#    #+#             */
/*   Updated: 2024/05/20 20:37:28 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void read_map_lines(t_data *d, int *lines_read)
{
    char *line;
	int count;

	line = NULL;
	count = 0;
    while (1)
	{
        line = get_next_line(d->fd);
        if (!line)
            break;
		if (count == 0)
			read_map_lines2(d, line);
        if (d->line_length < (int)ft_strlen(line))
            d->line_length = ft_strlen(line) - 1;
		if (ft_strcmp(line, "\n"))
		{
            printf("%s", line);
            (*lines_read)++;
			count++;
        }
		else if (!ft_strcmp(line, "\n") && count > 0)
			error_dup_elem(d, line, 12);
        free(line);
    }
}

void	read_map_lines2(t_data *d, char *line)
{
	int i;

	i = 0;
	while(line[i] && line[i] != '\n')
	{
		if (line[i] == ' ')
			i++;
		else
			break;
		if (line[i] == '\n')
			error_dup_elem(d, line, 13);
	}
	while(line[i] && line[i] != '\n')
	{
		if (check_value(line[i]))
			i++;
		else
			error_dup_elem(d, line, 13);
	}
}

void	process_map_line(t_data *d, char *line)
{
	int i;
	int j;

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
			while (j < d->line_length)
			{
				d->map_utils->map[i][j] = ' ';
				j++;
			}
		}
		d->map_utils->map[i][j] = '\n';
		d->map_utils->map[i][j + 1] = '\0';
	}
	else
	{
		error_dup_elem(d, line, 14);
	}
}

void populate_map(t_data *d, int lines_read, char *file_name)
{
    char *line;
	
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
            break;
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
    int lines_read;
	int i;

	lines_read = 0;
    i = d->map_utils->skip_count;
    d->fd = open(file_name, O_RDONLY);
    skip_lines(d, i);
    read_map_lines(d, &lines_read);
    populate_map(d, lines_read, file_name);
    if (is_map_closed(d) == 1)
        printf("Mapa FECHADO!\n");
    else
		printf("Mapa invalido!\n");
		//d->error = 0;
	d->map_utils->map[lines_read] = NULL;
	close(d->fd);
}

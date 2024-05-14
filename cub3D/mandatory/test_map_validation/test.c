/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:18:15 by bmota-si          #+#    #+#             */
/*   Updated: 2024/05/08 16:47:14 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int check_char(char *str)
{
	if (str[0] == '1')
		return (1);
	return (0);
}

int check_enter(char *str)
{
	if (str[0] == '\n')
		return (1);
	return (0);
}

int	check_for_spaces2(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] != ' ' && str[i] != '\t')
		return (1);
	return (0);
}

void obtain_row(t_data *d, int *rows, int *col)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(d->map_utils->map[i][j] == ' ' || d->map_utils->map[i][j] == '1' || d->map_utils->map[i][j] == '0')
	{
		if(d->map_utils->map[i][j] == ' ')
		{
			while(d->map_utils->map[i][j] == ' ')
				j++;
		}
		if(d->map_utils->map[i][j] == '1')
		{
			while(d->map_utils->map[i][j] == '1' || d->map_utils->map[i][j] == '0')
				j++;
		}
		if(d->map_utils->map[i][j] == '\n')
		{
			if(*col < j - 1)
				*col = j;
			j = 0;
			i++;
		}
	}
	*rows = i;
}

int check_coord(t_data *d, int i, int j, char a)
{
	if (i < d->line_height - 1)//exceto a ultima linha
		if (d->map_utils->map[i + 1][j])
			if (d->map_utils->map[i + 1][j] == a)
				return (0);
	if (i > 0)//exceto a primeira linha
		if (d->map_utils->map[i - 1][j])
			if (d->map_utils->map[i - 1][j] == a)
				return (0);
	if (d->map_utils->map[i][j] != '\n')//exceto a ultima coluna de cada linha
		if (d->map_utils->map[i][j + 1])
			if (d->map_utils->map[i][j + 1] == a)
				return (0);
	if (j > 0)//exceto a primeira coluna
		if (d->map_utils->map[i][j - 1])
			if (d->map_utils->map[i][j - 1] == a)
				return (0);
	return (1);
}

int check_value(char a)
{
	if (a != '1' && a != '0' && a != ' ' && a != '\n')
		if(a != 'N' && a != 'W' && a != 'E' && a != 'S')
			return (0);
	return (1);
}

int check_value2(t_data *d, int i, int j)
{
	if (d->map_utils->map[i][j] != '1' && d->map_utils->map[i][j] != '0' &&
			d->map_utils->map[i][j] != ' ' && d->map_utils->map[i][j] != '\n')
		if(d->map_utils->map[i][j] != 'N' && d->map_utils->map[i][j] != 'W' &&
				d->map_utils->map[i][j] != 'E' && d->map_utils->map[i][j] != 'S')
			return (d->error += 1);
	if(d->map_utils->map[i][j] == 'N' || d->map_utils->map[i][j] == 'W' ||
				d->map_utils->map[i][j] == 'E' || d->map_utils->map[i][j] == 'S')
	{
			d->map_utils->player_pos = d->map_utils->map[i][j];
			if(!check_player_position(d, i, j, '0'))
				return (d->error += 2);
			put_player_pos(d, i, j);
			d->map_utils->skip_count++;
			if(d->map_utils->skip_count > 1)
				return (d->error -= 1);
			if (!check_coord(d, i, j, ' '))
				return (d->error -= 1);
	}
	return (1);
}

int	check_player_position(t_data *d, int i, int j, char a)
{
	if (d->map_utils->map[i + 1][j])
		if (d->map_utils->map[i + 1][j] == a)
			return (1);
	if (d->map_utils->map[i - 1][j])
		if (d->map_utils->map[i - 1][j] == a)
			return (1);
	if (d->map_utils->map[i][j + 1])
		if (d->map_utils->map[i][j + 1] == a)
			return (1);
	if (d->map_utils->map[i][j - 1])
		if (d->map_utils->map[i][j - 1] == a)
			return (1);
	return (0);
}

void	put_player_pos(t_data *d, int y, int x)
{
	d->p_y = y + 0.5;
	d->p_x = x + 0.5;
}

int check_first_last(t_data *d)
{
	int j;
	
	j = 0;
	while(d->map_utils->map[0][j] && d->map_utils->map[0][j] != '\n')
	{
		if (d->map_utils->map[0][j] == '1' || d->map_utils->map[0][j] == ' ')
			j++;
		else
			return (0);
	}
	j = 0;
	d->line_height -= 1;
	while(d->map_utils->map[d->line_height][j] && d->map_utils->map[d->line_height][j] != '\n')
	{
		if (d->map_utils->map[d->line_height][j] == '1' || d->map_utils->map[d->line_height][j] == ' ')
			j++;
		else
			return (0);
	}
	return (1);
}

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

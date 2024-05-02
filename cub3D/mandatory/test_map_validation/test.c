/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:18:15 by bmota-si          #+#    #+#             */
/*   Updated: 2024/04/30 19:01:36 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int check_char(char *str)
{
	if(str[0] == '1')
		return (1);
	return (0);
}

int check_enter(char *str)
{
	if(str[0] == '\n')
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

int check_coord(t_data *d, int i, int j)
{
	if (i < d->line_height - 1)//exceto a ultima linha
		if (d->map_utils->map[i + 1][j])
			if (d->map_utils->map[i + 1][j] == '0')
				return (0);
	if (i > 0)//exceto a primeira linha
		if (d->map_utils->map[i - 1][j])
			if (d->map_utils->map[i - 1][j] == '0')
				return (0);
	if (d->map_utils->map[i][j] != '\n')//exceto a ultima coluna de cada linha
		if (d->map_utils->map[i][j + 1])
			if (d->map_utils->map[i][j + 1] == '0')
				return (0);
	if (j > 0)//exceto a primeira coluna
		if (d->map_utils->map[i][j - 1])
			if (d->map_utils->map[i][j - 1] == '0')
				return (0);
	/* if (i < d->map_utils->skip_count - 1 && d->map_utils->map[i][j] != '\n')//exceto ultima linha e ultima coluna
		if (d->map_utils->map[i + 1][j + 1])
			if (d->map_utils->map[i + 1][j + 1] == '0')
				return (0);
	if (i > 0 && j > 0)//exceto primeira linha e primeira coluna
		if (d->map_utils->map[i - 1][j - 1])
			if (d->map_utils->map[i - 1][j - 1] == '0')
				return (0);
	if (j > 0 && i < d->map_utils->skip_count - 1)//exceto a primeira coluna e ultima linha
		if (d->map_utils->map[i + 1][j - 1])
			if (d->map_utils->map[i + 1][j - 1] == '0')
				return (0);
	if (i > 0 && d->map_utils->map[i][j] != '\n')//exceto a primeira linha e ultima coluna
		if (d->map_utils->map[i - 1][j + 1])
			if (d->map_utils->map[i - 1][j + 1] == '0')
				return (0); */
	return (1);
}

int check_value(char a)
{
	if (a != '1' && a != '0' && a != ' ' && a != '\n')
		if(a != 'N' && a != 'W' && a != 'E' && a != 'S')
			return (0);
	return (1);
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

int is_map_closed2(t_data *d)
{
	int i;
	int j;

	i = 0;
	j = 0;
	//put_spaces(d->map_utils->map[i])
	if (!check_first_last(d))
		return (0);
	while(d->map_utils->map[i][j])
	{
		if (!check_value(d->map_utils->map[i][j]))
			return (0);
		if (d->map_utils->map[i][j] == ' ' || d->map_utils->map[i][j] == '\n')
			if(check_coord(d, i, j) == 0)
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

int	is_map_closed(t_data *d)
{
	int i;
	int j;
	int rows;
	int col;
	
	i = 0;
	j = 0;
	rows = 0;
	col = 0;
	obtain_row(d, &rows, &col);
	printf("%i, %i", rows, col);
	while(d->map_utils->map[i][j] == '1')
		i++;
	rows = i;
	i = 0;
	while(d->map_utils->map[i][j] == '1')
		j++;
	col = j;
	j = 0;
	while(d->map_utils->map[i][j] == '1')//Verifica a primeira linha
	{
		if(d->map_utils->map[i][j + 1] == '0')
			return (0);
		j++;
	}
	j = 0;
	while(d->map_utils->map[i][j] == '1')//Verifica a primeira coluna
	{
		if(d->map_utils->map[i + 1][j] == '0')
			return (0);
		i++;
	}
	i = 0;
	while(d->map_utils->map[rows - 1][j] == '1')//Verifica a ultima linha
	{
		if(d->map_utils->map[rows - 1][j + 1] == '0')
			return (0);
		j++;
	}
	while(d->map_utils->map[i][col - 1] == '1')//Verifica a ultima coluna
	{
		if(d->map_utils->map[i + 1][col - 1] == '0')
			return (0);
		i++;
	}
	return (1);
}

void	map_validation_test(t_data *d, char *file_name)
{
    char *line;
	int i;
	int j;

	i = d->map_utils->skip_count;
    d->fd = open(file_name, O_RDONLY);
    while (i != 0) 
	{
        line = get_next_line(d->fd);
        if (!line)
            break;
		i--;
        free(line);
    }
	if (line)
		i = d->map_utils->skip_count;
	while (line)
	{
		line = get_next_line(d->fd);
		if (!line)
			break;
		if (d->line_length < (int)ft_strlen(line))
			d->line_length = ft_strlen(line) - 1;
		if (ft_strcmp(line, "\n"))
		{
			printf("%s", line);
			i++;
		}
		free(line);
	}
	printf("%i linhas!\n", i - d->map_utils->skip_count);
	d->line_height = i - d->map_utils->skip_count;
	d->map_utils->map = malloc(sizeof(char *) * i + 1);
	i = 0;
	close(d->fd);
	d->fd = open(file_name, O_RDONLY);
	while (i < 6)
    {
		free(line);
		line = get_next_line(d->fd);
		i++;
	}
	free(line);
	line = get_next_line(d->fd);
	i = 0;
	while(line)
	{
		j = 0;
		free(line);
		line = get_next_line(d->fd);
		/* if (!ft_strcmp(line, "\t"))//Se existir linhas com tab ignora a linha!
		{
			free(line);
			line = get_next_line(d->fd);
		} */
		if(!line)
			break;
		if(check_enter(line))
			;
		else if (check_char(line))
		{
			d->map_utils->map[i] = malloc(sizeof(char) * (d->line_length + 2));
			while(j < d->line_length)
			{
				while(line[j] != '\0' && line[j] != '\n')
				{
					d->map_utils->map[i][j] = line[j];
					//printf("map*%s", d->map_utils->map[i]);
					j++;		
				}
				/* if(line[j] == '\n')
					d->map_utils->map[i][j] = ' ';
				j++; */
				while(j < d->line_length)
				{
					d->map_utils->map[i][j] = ' ';
					j++;
				}
			}
			d->map_utils->map[i][j] = '\n';
			d->map_utils->map[i][j + 1] = '\0';
			i++;
		}
		else
			error_dup_elem(d, line);
		//printf("%s", line);
	}
	d->map_utils->map[i] = "\0";
	if(is_map_closed2(d))
		printf("Mapa FECHADO!\n");
	else
		printf("Mapa invalido!\n");
	d->map_utils->map[i] = NULL;
	close(d->fd);
}

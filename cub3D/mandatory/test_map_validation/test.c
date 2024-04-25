/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:18:15 by bmota-si          #+#    #+#             */
/*   Updated: 2024/04/23 15:55:34 by bmota-si         ###   ########.fr       */
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
	
    i = 0;
    d->fd = open(file_name, O_RDONLY);
	line = get_next_line(d->fd);
	while (i < 6)
    {
		free(line);
		line = get_next_line(d->fd);
		i++;
	}
	free(line);
    while (1) 
	{
        line = get_next_line(d->fd);
        if (!line || line[0] != '\n')
		{
            //free(line);
            break;
        }
        free(line);
    }
	if (line)
		i = 1;
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(d->fd);
		i++;
	}
	free(line);
	printf("%i\n", i);
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
			d->map_utils->map[i] = ft_strdup(line);
			//printf("map*%s", d->map_utils->map[i]);
			i++;
		}
		else
			error_dup_elem(d, line);
		//printf("%s", line);
	}
	d->map_utils->map[i] = "\0";
	if(is_map_closed(d))
		printf("Mapa FECHADO!\n");
	else
		printf("Mapa invalido!\n");
	d->map_utils->map[i] = NULL;
	close(d->fd);
}
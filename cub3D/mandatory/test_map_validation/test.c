/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:18:15 by bmota-si          #+#    #+#             */
/*   Updated: 2024/04/18 17:19:57 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	map_validation_test(t_data *d, char *file_name)
{
    char *line;
	char **map;
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
	printf("%s", line);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(d->fd);
		i++;
	}
	free(line);
	printf("%i\n", i);
	map = malloc(sizeof(char *) * i + 1);
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
		if (!line)
			break;
		printf("%s", line);
		map[i] = ft_strdup(line);
		printf("*MAP*%s", map[i]);
		i++;
	}
	map[5] = NULL;
	ft_free_str_array(&map);
	close(d->fd);
}
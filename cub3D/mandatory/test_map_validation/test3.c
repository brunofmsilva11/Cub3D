/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:35:56 by bruno             #+#    #+#             */
/*   Updated: 2024/05/20 20:36:30 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

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

int check_value(char a)
{
	if (a != '1' && a != '0' && a != ' ' && a != '\n')
		if(a != 'N' && a != 'W' && a != 'E' && a != 'S')
			return (0);
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

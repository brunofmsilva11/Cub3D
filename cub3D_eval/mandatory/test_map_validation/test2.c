/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:34:23 by bruno             #+#    #+#             */
/*   Updated: 2024/05/22 17:25:56 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_char(char *str)
{
	if (str[0] == '1' || str[0] == ' ')
		return (1);
	return (0);
}

int	check_enter(char *str)
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

int	check_coord(t_data *d, int i, int j, char a)
{
	if (i < d->line_height - 1)
		if (d->map_utils->map[i + 1][j])
			if (d->map_utils->map[i + 1][j] == a)
				return (0);
	if (i > 0)
		if (d->map_utils->map[i - 1][j])
			if (d->map_utils->map[i - 1][j] == a)
				return (0);
	if (d->map_utils->map[i][j] != '\n')
		if (d->map_utils->map[i][j + 1])
			if (d->map_utils->map[i][j + 1] == a)
				return (0);
	if (j > 0)
		if (d->map_utils->map[i][j - 1])
			if (d->map_utils->map[i][j - 1] == a)
				return (0);
	return (1);
}

int	check_value2(t_data *d, int i, int j)
{
	if (d->map_utils->map[i][j] != '1' && d->map_utils->map[i][j] != '0' &&
			d->map_utils->map[i][j] != ' ' && d->map_utils->map[i][j] != '\n')
		if (d->map_utils->map[i][j] != 'N' && d->map_utils->map[i][j] != 'W' &&
				d->map_utils->map[i][j] != 'E' &&
					d->map_utils->map[i][j] != 'S')
			return (d->error += 1);
	if (d->map_utils->map[i][j] == 'N' || d->map_utils->map[i][j] == 'W' ||
				d->map_utils->map[i][j] == 'E' ||
					d->map_utils->map[i][j] == 'S')
	{
		d->map_utils->player_pos = d->map_utils->map[i][j];
		if (!check_player_position(d, i, j, '0'))
			return (d->error += 2);
		put_player_pos(d, i, j);
		d->map_utils->skip_count++;
		if (d->map_utils->skip_count > 1)
			return (d->error -= 1);
		if (!check_coord(d, i, j, ' '))
			return (d->error -= 1);
	}
	return (1);
}

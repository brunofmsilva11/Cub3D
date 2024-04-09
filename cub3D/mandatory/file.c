/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:04:36 by bmota-si          #+#    #+#             */
/*   Updated: 2024/04/09 17:08:49 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	args_in_file(t_data *d, char *file_name)
{
	char	*line;

	d->fd = open(file_name, O_RDONLY);
	/* while (!d->map_utils->no || !d->map_utils->f_color || !d->map_utils->we
		|| !d->map_utils->ea || !d->map_utils->so || !d->map_utils->c_color) */
    while (!d->map_utils->f_color || d->map_utils->c_color)
	{
		line = get_next_line(d->fd);
		if (ft_strchr(" 1", line[0]))
		{
			free(line);
			//ft_no_leak(d, line);
			//ft_free_game(d);
			finish_error("Error: invalid element position!\n", 2);
		}
		/* if (!valid_info2(d, line) && line[0] != '\n')
			error_in_elem(d, line); */
		free(line);
		d->map_utils->skip_count++;
	}
	//ft_no_leak(d, line);
	//ft_check_textures(d);
	//map_to_file(d, file_name);
}

int	valid_info2(t_data *d, char *line)
{
	(void)d;
    if (!ft_strncmp("F ", line, 2))
	{
		/* if (d->map_utils->f_color)
			error_dup_elem(d, line); */
		//put_rgb(d, line, 1);
		return (1);
	}
	else if (!ft_strncmp("C ", line, 2))
	{
		/* if (d->map_utils->c_color)
			error_dup_elem(d, line); */
		//put_rgb(d, line, 2);
		return (1);
	}
	return (0);
}

/* void	error_in_elem(t_data *d, char *line)
{
	free(line);
	//ft_no_leak(d, line);
	//ft_free_game(d);
	finish_error("Error: invalid element!\n", 2);
}
void	error_dup_elem(t_data *d, char *line)
{
	free(line);
	//ft_no_leak(d, line);
	//ft_free_game(d);
	finish_error("Error: duplicate elements!\n", 2);
} */

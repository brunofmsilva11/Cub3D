/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:04:36 by bmota-si          #+#    #+#             */
/*   Updated: 2024/04/10 15:59:11 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	valid_info(t_data *d, char *line)
{
	int	r;

	r = 0;
	if (!ft_strncmp("NO ", line, 3))
	{
		if (d->map_utils->no)
			printf("Erro NO!");
			//error_dup_elem(d, line);
		path_image(d, line, 1);
		return (1);
	}
	else if (!ft_strncmp("SO ", line, 3))
	{
		if (d->map_utils->so)
			printf("Erro SO!");
			//error_dup_elem(d, line);
		path_image(d, line, 2);
		return (1);
	}
	if (valid_info1(d, line) == 1)
		r = 1;
	else if (valid_info2(d, line) == 1)
		r = 1;
	return (r);
}

int	valid_info1(t_data *d, char *line)
{
	if (!ft_strncmp("WE ", line, 3))
	{
		if (d->map_utils->we)
			printf("Erro WE!");
			//error_dup_elem(d, line);
		path_image(d, line, 3);
		return (1);
	}
	else if (!ft_strncmp("EA ", line, 3))
	{
		if (d->map_utils->ea)
			printf("Erro EA!");
			//error_dup_elem(d, line);
		path_image(d, line, 4);
		return (1);
	}
	return (0);
}

int	valid_info2(t_data *d, char *line)
{
	(void)d;
    if (!ft_strncmp("F ", line, 2))
	{
		if (d->map_utils->f_color)
			printf("Erro F_color!");
			//error_dup_elem(d, line);
		put_rgb(d, line, 1);
		return (1);
	}
	else if (!ft_strncmp("C ", line, 2))
	{
		if (d->map_utils->c_color)
			printf("Erro C_color!");
			//error_dup_elem(d, line);
		put_rgb(d, line, 2);
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

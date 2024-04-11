/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direc_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:01:30 by bmota-si          #+#    #+#             */
/*   Updated: 2024/04/11 12:13:57 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	valid_info(t_data *d, char *line)
{
	int	r;

	r = 0;
	if (!ft_strncmp("NO ", line, 3))
	{
		if (d->map_utils->no)
		{
			free(line);
			ft_no_leak(d, line);
			ft_free_data(d);
			finish_error("Error: duplicate elements!\n", 2);
		}
		path_image(d, line, 1);
		return (1);
	}
	else if (!ft_strncmp("SO ", line, 3))
	{
		if (d->map_utils->so)
		{
			free(line);
			ft_no_leak(d, line);
			ft_free_data(d);
			finish_error("Error: duplicate elements!\n", 2);
		}
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
		{
			free(line);
			ft_no_leak(d, line);
			ft_free_data(d);
			finish_error("Error: duplicate elements!\n", 2);
		}
		path_image(d, line, 3);
		return (1);
	}
	else if (!ft_strncmp("EA ", line, 3))
	{
		if (d->map_utils->ea)
		{
			free(line);
			ft_no_leak(d, line);
			ft_free_data(d);
			finish_error("Error: duplicate elements!\n", 2);
		}
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
		{
			free(line);
			ft_no_leak(d, line);
			ft_free_data(d);
			finish_error("Error: duplicate elements!\n", 2);
		}
		put_rgb(d, line, 1);
		return (1);
	}
	else if (!ft_strncmp("C ", line, 2))
	{
		if (d->map_utils->c_color)
		{
			free(line);
			ft_no_leak(d, line);
			ft_free_data(d);
			finish_error("Error: duplicate elements!\n", 2);
		}
		put_rgb(d, line, 2);
		return (1);
	}
	return (0);
}

void	path_image(t_data *d, char *line, int flag)
{
	char	*temp;

	temp = ft_strdup(line + 3);
	if (flag == 1 && !d->map_utils->no)
		d->map_utils->no = ft_strtrim(temp, " \t\n");
	else if (flag == 2 && !d->map_utils->so)
		d->map_utils->so = ft_strtrim(temp, " \t\n");
	else if (flag == 3 && !d->map_utils->we)
		d->map_utils->we = ft_strtrim(temp, " \t\n");
	else if (flag == 4 && !d->map_utils->ea)
		d->map_utils->ea = ft_strtrim(temp, " \t\n");
	free(temp);
	return ;
}

void	error_in_elem(t_data *d, char *line)
{
	free(line);
	ft_no_leak(d, line);
	ft_free_data(d);
	finish_error("Error: invalid element!\n", 2);
}

void	error_dup_elem(t_data *d, char *line)
{
	free(line);
	ft_no_leak(d, line);
	ft_free_data(d);
	finish_error("Error: duplicate elements!\n", 2);
}

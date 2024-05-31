/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:22:47 by bmota-si          #+#    #+#             */
/*   Updated: 2024/05/31 10:45:23 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_free_data7(t_data *d)
{
	if (d->map_utils->flag_c)
		ft_free_str_array(&d->map_utils->c_color);
	if (d->map_utils->flag_f)
		ft_free_str_array(&d->map_utils->f_color);
	if (d->map_utils->map)
		ft_free_str_array(&d->map_utils->map);
	if (d->map_utils->ea)
		free(d->map_utils->ea);
	if (d->map_utils->no)
		free(d->map_utils->no);
	if (d->map_utils->so)
		free(d->map_utils->so);
	if (d->map_utils->we)
		free(d->map_utils->we);
	if (d->map_utils)
		free(d->map_utils);
	free(d);
}

void	ft_free_data8(t_data *d)
{
	if (d->map_utils->flag_c)
		ft_free_str_array(&d->map_utils->c_color);
	if (d->map_utils->flag_f)
		ft_free_str_array(&d->map_utils->f_color);
	if (d->map_utils->map)
		ft_free_str_array2(d->map_utils->map);
	if (d->map_utils->ea)
		free(d->map_utils->ea);
	if (d->map_utils->no)
		free(d->map_utils->no);
	if (d->map_utils->so)
		free(d->map_utils->so);
	if (d->map_utils->we)
		free(d->map_utils->we);
	if (d->map_utils)
		free(d->map_utils);
	free(d);
}

void	ft_free_str_array2(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			arr[i] = NULL;
			i++;
		}
		free(arr);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:33:57 by bmota-si          #+#    #+#             */
/*   Updated: 2024/05/22 15:26:35 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_check_textures(t_data *d)
{
	int	i;

	i = ft_strlen(d->map_utils->no) - 1;
	while (d->map_utils->no[i] != '.' && i != 0)
		i--;
	if (!string_comp(d->map_utils->no + i, ".xpm"))
	{
		ft_free_data2(d);
		finish_error("Error\nNO texture isn't .xpm!\n", 2);
	}
	i = ft_strlen(d->map_utils->so) - 1;
	while (d->map_utils->so[i] != '.' && i != 0)
		i--;
	if (!string_comp(d->map_utils->so + i, ".xpm"))
	{
		ft_free_data2(d);
		finish_error("Error\nSO texture isn't .xpm!\n", 2);
	}
	ft_check_textures2(d);
}

void	ft_check_textures2(t_data *d)
{
	int	i;

	i = ft_strlen(d->map_utils->we) - 1;
	while (d->map_utils->we[i] != '.' && i != 0)
		i--;
	if (!string_comp(d->map_utils->we + i, ".xpm"))
	{
		ft_free_data2(d);
		finish_error("Error\nWE texture isn't .xpm!\n", 2);
	}
	i = ft_strlen(d->map_utils->ea) - 1;
	while (d->map_utils->ea[i] != '.' && i != 0)
		i--;
	if (!string_comp(d->map_utils->ea + i, ".xpm"))
	{
		ft_free_data2(d);
		finish_error("Error\nEA texture isn't .xpm!\n", 2);
	}
}

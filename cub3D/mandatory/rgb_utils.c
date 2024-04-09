/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:15:09 by bmota-si          #+#    #+#             */
/*   Updated: 2024/04/09 17:06:39 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_rgb(t_data *d, char *line, int flag)
{
	int	i;

	i = 0;
	d->map_utils->color_aux = ft_split(line + 2, ',');
	/* if (ft_count(line, ',') != 2 || ft_check_next_comma(line) == 1)
		error_handling(line, d, "Error: Wrong number of color values!\n"); */
	while (i < 3)
	{
		/* if (ft_verify_digits(d->map_utils->color_aux[i], i))
			error_handling(line, d, "Error: Wrong value in RGB!\n");
		if (!(ft_atoi(d->map_utils->color_aux[i]) >= 0
				&& ft_atoi(d->map_utils->color_aux[i]) <= 255))
			error_handling(line, d, "Error: Wrong value in RGB!\n"); */
		i++;
	}
	if (flag == 1)
		put_fc_rgb(d, flag, line);
	else if (flag == 2)
		put_fc_rgb(d, flag, line);
	free_double_pointer(d->map_utils->color_aux);
}
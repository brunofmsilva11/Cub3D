/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:46:36 by bmota-si          #+#    #+#             */
/*   Updated: 2024/05/22 11:57:29 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	*data;

	(void)av;
	if (ac != 2)
	{
		ft_putstr_fd("Error\nCheck the input-->./cub3D <Map path>\n", 2);
		return (0);
	}
	data = malloc(sizeof(t_data));
	data->map_utils = malloc(sizeof(t_map));
	ft_init_stack(data);
	ft_check_map_file(data, av[1]);
	if (data->error == 1 && data->map_utils->player_pos)
	{
		ft_start(data);
		ft_free_data(data);
	}
	else if (data->error == 2)
		error_dup_elem(data, NULL, 14);
	else if (data->error == 3)
		error_dup_elem(data, NULL, 15);
	else
		error_dup_elem(data, NULL, 10);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:46:36 by bmota-si          #+#    #+#             */
/*   Updated: 2024/04/09 17:32:32 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_null_file(t_data *d, char *file_name)
{
	char	*line;

	d->fd = open(file_name, O_RDONLY);
	line = get_next_line(d->fd);
	if (!line)
	{
		//ft_free_game(d);
		finish_error("Error: no content on file\n", 2);
	}
	free(line);
	//ft_no_leak2(d, line);
	close(d->fd); //nao manter!!!
}

void	ft_check_map_file(t_data *d, char *file_name)
{
	int	i;
	char *dup;

	//i = ft_strlen(file_name) - 1;
	i = 0;
	dup = ft_strdup(file_name);
	while (file_name[i] != '.')
	{
		if (!file_name[i])
			file_name_error(d);
		dup++;
		i++;
	}
	if (ft_strcmp((dup), ".cub"))
		file_name_error(d);
	//free(dup);
	d->fd = open(file_name, O_RDONLY);
	if (d->fd < 0)
	{
		free(d->map_utils);
		free(d);
		finish_error("Error\nInvalid FD\n", 2);
	}
	close(d->fd);
	d->fd = 0;
	check_null_file(d, file_name);
	args_in_file(d, file_name);
}

int	main(int ac, char **av)
{
	t_data	*game;

	(void)av;
	if (ac != 2)
	{
		ft_putstr_fd("Error\nCheck the input-->./Cub3D <Map path>\n", 2);
		return (0);
	}
	game = malloc(sizeof(t_data));
	game->map_utils = malloc(sizeof(t_map));
	ft_init_stack(game);
	ft_check_map_file(game, av[1]);
	void	*mlx_ptr;
	void	*win_ptr;
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (1);
	init_struct_imgs(game);
	ft_init_stack3(game);
	get_imgs_xpm(game);
	win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "CUB3D");
	mlx_loop(mlx_ptr);
	return (0);
}

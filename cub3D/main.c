/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:46:36 by bmota-si          #+#    #+#             */
/*   Updated: 2024/04/10 16:40:57 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    print_int(void *mlx_ptr, void *win_ptr, int x, int y, int color, int num)
{
    char str[12];  // Buffer para conter o número inteiro, incluindo sinal e terminador nulo
    sprintf(str, "%d", num);  // Converte o inteiro para string
    mlx_string_put(mlx_ptr, win_ptr, x, y, color, str);
}

/* static void	check_null_file(t_data *d, char *file_name)
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
} */

int	ft_finish(t_data *g)
{
/* 	mlx_destroy_image(g->mlx, g->floor_img);
	mlx_destroy_image(g->mlx, g->wall_img);
	mlx_destroy_image(g->mlx, g->playera_img);
	mlx_destroy_image(g->mlx, g->playerw_img);
	mlx_destroy_image(g->mlx, g->playerd_img);
	mlx_destroy_image(g->mlx, g->players_img);
	mlx_destroy_image(g->mlx, g->playerf_img);
	mlx_destroy_image(g->mlx, g->exit_img);
	mlx_destroy_image(g->mlx, g->collect_img); */
	mlx_destroy_window(g->mlx_ptr, g->win_ptr);
	mlx_destroy_display(g->mlx_ptr);
	free(g->map_utils);
	free(g);
	//ft_free_map(g);
	//free(g->mlx);
	exit(0);
}

int	handle_input(int keysym, t_data *g)
{
	int	result;

	result = 0;
	if (keysym == XK_Escape)
		ft_finish (g);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*game;
	int i;
	int x;

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
	//get_imgs_xpm(game);
	win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "CUB3D");
	win_ptr = mlx_new_window(mlx_ptr, 800, 800, "Dados_CUB3D");
	mlx_string_put(mlx_ptr, win_ptr, 50, 50, 0x00FFFFFF, game->map_utils->no);
	mlx_string_put(mlx_ptr, win_ptr, 150, 150, 0x00FFFFFF, game->map_utils->so);
	mlx_string_put(mlx_ptr, win_ptr, 250, 250, 0x00FFFFFF, game->map_utils->ea);
	mlx_string_put(mlx_ptr, win_ptr, 350, 350, 0x00FFFFFF, game->map_utils->we);
	i = 0;
	x = 450;
	while(game->map_utils->f_color[i] && game->map_utils->c_color[i])
	{
		mlx_string_put(mlx_ptr, win_ptr, x, 450, 0x00FFFFFF, game->map_utils->f_color[i]);
		mlx_string_put(mlx_ptr, win_ptr, x, 550, 0x00FFFFFF, game->map_utils->c_color[i]);
		i++;
		x+=100;	
	}
	mlx_hook(win_ptr, KeyPress, KeyPressMask, handle_input, &game);
	mlx_hook(win_ptr, DestroyNotify, ButtonPressMask, ft_finish, &game);
	mlx_loop(mlx_ptr);
	return (0);
}

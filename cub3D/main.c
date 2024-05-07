/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:46:36 by bmota-si          #+#    #+#             */
/*   Updated: 2024/05/07 18:30:16 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_start(t_data *d)
{
	d->mlx_ptr = mlx_init();
	if (d->mlx_ptr == NULL)
		return ;
	init_struct_imgs(d);
	ft_init_stack3(d);
	get_imgs_xpm(d);
	d->win_ptr = mlx_new_window(d->mlx_ptr, WIDTH, HEIGHT, "CUB3D");
	put_color_on_window(d);
	//d->win_ptr = mlx_new_window(d->mlx_ptr, 800, 800, "Dados_CUB3D");
	/* mlx_string_put(d->mlx_ptr, d->win_ptr, 50, 50, 0x00FFFFFF, d->map_utils->no);
	mlx_string_put(d->mlx_ptr, d->win_ptr, 150, 150, 0x00FFFFFF, d->map_utils->so);
	mlx_string_put(d->mlx_ptr, d->win_ptr, 250, 250, 0x00FFFFFF, d->map_utils->ea);
	mlx_string_put(d->mlx_ptr, d->win_ptr, 350, 350, 0x00FFFFFF, d->map_utils->we);
	i = 0;
	x = 450;
	while(d->map_utils->f_color[i] && d->map_utils->c_color[i])
	{
		mlx_string_put(d->mlx_ptr, d->win_ptr, x, 450, 0x00FFFFFF, d->map_utils->f_color[i]);
		mlx_string_put(d->mlx_ptr, d->win_ptr, x, 550, 0x00FFFFFF, d->map_utils->c_color[i]);
		i++;
		x+=100;
	} */
	mlx_hook(d->win_ptr, KeyPress, KeyPressMask, handle_input, d);//Quando esc e carregado fecha programa e da frees!
	mlx_hook(d->win_ptr, DestroyNotify, ButtonPressMask, ft_exit_x, d);//Quando X e carregado fecha programa e da frees!
	mlx_loop(d->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_data	*data;

	(void)av;
	if (ac != 2)
	{
		ft_putstr_fd("Error\nCheck the input-->./Cub3D <Map path>\n", 2);
		return (0);
	}
	data = malloc(sizeof(t_data));
	data->map_utils = malloc(sizeof(t_map));
	ft_init_stack(data);//inicia as variaveis de data
	ft_check_map_file(data, av[1]);//Verifica se o mapa e valido!
	ft_start(data);//inicia o jogo
	ft_free_data(data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:46:36 by bmota-si          #+#    #+#             */
/*   Updated: 2024/04/17 11:36:36 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	*data;
	/* int i;
	int x; */

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
	
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (1);
	init_struct_imgs(data);
	ft_init_stack3(data);
	//get_imgs_xpm(data);
	/* data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "CUB3D");
	put_color_on_window(data);
	//win_ptr = mlx_new_window(mlx_ptr, 800, 800, "Dados_CUB3D");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 50, 0x00FFFFFF, data->map_utils->no);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 150, 150, 0x00FFFFFF, data->map_utils->so);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 250, 250, 0x00FFFFFF, data->map_utils->ea);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 350, 350, 0x00FFFFFF, data->map_utils->we);
	i = 0;
	x = 450;
	while(data->map_utils->f_color[i] && data->map_utils->c_color[i])
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, x, 450, 0x00FFFFFF, data->map_utils->f_color[i]);
		mlx_string_put(data->mlx_ptr, data->win_ptr, x, 550, 0x00FFFFFF, data->map_utils->c_color[i]);
		i++;
		x+=100;	
	}
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, handle_input, data);//Quando esc e carregado fecha programa e da frees!
	mlx_hook(data->win_ptr, DestroyNotify, ButtonPressMask, ft_exit_x, data);//Quando X e carregado fecha programa e da frees!
	mlx_loop(data->mlx_ptr); */
	ft_free_data(data);
	//free(data->win_ptr);
	//free(data->mlx_ptr);
	return (0);
}

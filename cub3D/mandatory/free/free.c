/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:01:38 by bmota-si          #+#    #+#             */
/*   Updated: 2024/05/20 15:24:13 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_free_data(t_data *d)
{
	if (d->map_utils->flag_c)
		ft_free_str_array(&d->map_utils->c_color);
	if (d->map_utils->flag_f)
		ft_free_str_array(&d->map_utils->f_color);
	if (d->map_utils->map)
		ft_free_str_array(&d->map_utils->map);
	if (d->map_utils->map_dup)
		ft_free_str_array(&d->map_utils->map_dup);
	if (d->map_utils->color_aux)
		ft_free_str_array(&d->map_utils->color_aux);
	if (d->map_utils->ea)
		free(d->map_utils->ea);
	if (d->map_utils->no)
		free(d->map_utils->no);
	if (d->map_utils->so)
		free(d->map_utils->so);
	if (d->map_utils->we)
		free(d->map_utils->we);
	ft_free_data3(d);
	free(d->map_utils);
	if (d->win_ptr)
		mlx_destroy_window(d->mlx_ptr, d->win_ptr);
	mlx_destroy_display(d->mlx_ptr);
	free(d->mlx_ptr);
	free(d);
}

/*free quando da erro antes de iniciar a janela do jogo 
ou seja, antes de entrar na funcao ft_start*/
void	ft_free_data2(t_data *d)
{
	if (d->map_utils->flag_c)
		ft_free_str_array(&d->map_utils->c_color);
	if (d->map_utils->flag_f)
		ft_free_str_array(&d->map_utils->f_color);
	if (d->map_utils->map)
		ft_free_str_array(&d->map_utils->map);
	if (d->map_utils->map_dup)
		ft_free_str_array(&d->map_utils->map_dup);
	if (d->map_utils->color_aux)
		ft_free_str_array(&d->map_utils->color_aux);
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

/*Acrescentei esta funcao para dar free as estruturas de 
cada imagem e a propria imagem isto so acontece depois
do mapa ser valido*/
void	ft_free_data3(t_data *d)
{
	if (d->n_img->img)
		mlx_destroy_image(d->mlx_ptr, d->n_img->img);
	if (d->s_img->img)
		mlx_destroy_image(d->mlx_ptr, d->s_img->img);
	if (d->w_img->img)
		mlx_destroy_image(d->mlx_ptr, d->w_img->img);
	if (d->e_img->img)
		mlx_destroy_image(d->mlx_ptr, d->e_img->img);
	free(d->n_img);
	free(d->s_img);
	free(d->w_img);
	free(d->e_img);
	mlx_destroy_image(d->mlx_ptr, d->img->img);
	free(d->img);
}

void	ft_no_leak(t_data *d, char *line)
{
	while (1)
	{
		line = get_next_line(d->fd);
		if (!line)
			break ;
		check_direc(d, line);
		free(line);
	}
	close(d->fd);
}

/*esta funcao serve para quando esta a verificar se o 
ficheiro e NULL as variaveis nao assumirem logo o valor!*/
void	ft_no_leak2(t_data *d, char *line)
{
	while (1)
	{
		line = get_next_line(d->fd);
		if (!line)
			break ;
		free(line);
	}
	close(d->fd);
}

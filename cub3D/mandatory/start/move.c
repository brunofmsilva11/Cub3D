/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:24:57 by bmota-si          #+#    #+#             */
/*   Updated: 2024/05/15 15:13:24 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*A função game_loop é o coração do ciclo de jogo. Aqui está uma explicação linha por linha:

    if (!ft_movs(d)) return (0);: Verifica se o jogador realizou algum movimento. A função ft_movs provavelmente verifica a entrada do jogador e atualiza a posição ou o estado do jogo conforme necessário. Se nenhum movimento for feito ou o jogo encerrar, a função retorna 0, indicando que o ciclo de jogo deve ser interrompido.

    mlx_destroy_image(d->mlx_ptr, d->img->img);: Destroi a imagem anteriormente criada no ciclo de jogo anterior. Isso é feito para evitar vazamentos de memória e garantir que a nova imagem seja criada corretamente.

    d->img->img = mlx_new_image(d->mlx_ptr, WIDTH, HEIGHT);: Cria uma nova imagem usando a função mlx_new_image fornecida pela biblioteca gráfica (presumivelmente, a biblioteca MLX). Esta imagem será usada para renderizar a cena atualizada.

    draw_raycast(d);: Chama a função draw_raycast, que é responsável por renderizar a cena usando a técnica de raycasting. Esta função desenha a cena atualizada na nova imagem criada.

    return (0);: Retorna 0 para indicar que o ciclo de jogo foi executado com sucesso.

Essa função constitui um ciclo básico de jogo, onde o estado do jogo é atualizado, a cena é renderizada e o processo é repetido continuamente até que o jogo termine ou o jogador decida sair.*/
int	game_loop(t_data *d)
{
	if (!ft_movs(d))
		return (0);
	mlx_destroy_image(d->mlx_ptr, d->img->img);
	d->img->img = mlx_new_image(d->mlx_ptr, WIDTH, HEIGHT);
	draw_raycast(d);
	return (0);
}

/*Esta função é chamada no loop principal do jogo para lidar
com os movimentos do jogador. Ela verifica se alguma tecla 
de movimento foi pressionada e chama as funções apropriadas 
para mover o jogador ou rotacioná-lo. Se alguma tecla de 
movimento for pressionada, a função retorna 1, 
indicando que houve um movimento; caso contrário, retorna 0.*/
int	ft_movs(t_data *d)
{
	if (d->key_press_up == 1)
		move_vertical(d, 1);
	if (d->key_press_down == 1)
		move_vertical(d, 0);
	if (d->key_press_right == 1)
		move_horizontal(d, 1);
	if (d->key_press_left == 1)
		move_horizontal(d, 0);
	if (d->key_press_r_left == 1)
		rotate_player(d, -1);
	if (d->key_press_r_right == 1)
		rotate_player(d, 1);
	if (d->key_press_up || d->key_press_down || d->key_press_left
		|| d->key_press_right || d->key_press_r_left || d->key_press_r_right)
		return (1);
	return (0);
}

/*Esta função move o jogador para frente ou para trás, 
dependendo do valor do argumento dir_flag. Se dir_flag 
for 1, o jogador move para frente; se for 0, o jogador 
move para trás. A função verifica se o próximo ponto para 
onde o jogador se moveria não está colidindo com uma parede 
(representada pelo caractere '1' no mapa) antes de atualizar 
a posição do jogador.*/
void	move_vertical(t_data *d, int dir_flag)
{
	if (dir_flag)
	{
		if (d->map_utils->map[(int)(d->p_y + d->dir_y * 0.1)]
			[(int) d->p_x] != '1')
			d->p_y += d->dir_y * 0.1;
		if (d->map_utils->map[(int)d->p_y]
			[(int)(d->p_x + d->dir_x * 0.1)] != '1')
			d->p_x += d->dir_x * 0.1;
	}
	else
	{
		if (d->map_utils->map[(int)(d->p_y - d->dir_y * 0.1)]
			[(int) d->p_x] != '1')
			d->p_y -= d->dir_y * 0.1;
		if (d->map_utils->map[(int)d->p_y]
			[(int)(d->p_x - d->dir_x * 0.1)] != '1')
			d->p_x -= d->dir_x * 0.1;
	}
}

/*Similar à função move_vertical, esta função move o jogador 
para os lados, dependendo do valor do argumento dir_flag. 
Se dir_flag for 1, o jogador move para a direita; se for 0, 
o jogador move para a esquerda. Novamente, a função verifica 
se o próximo ponto para onde o jogador se moveria não 
está colidindo com uma parede antes de atualizar a posição.*/
void	move_horizontal(t_data *d, int dir_flag)
{
	if (dir_flag)
	{
		if (d->map_utils->map[(int)(d->p_y + d->dir_x * 0.1)]
			[(int) d->p_x] != '1')
			d->p_y += d->dir_x * 0.1;
		if (d->map_utils->map[(int)d->p_y]
			[(int)(d->p_x - d->dir_y * 0.1)] != '1')
			d->p_x -= d->dir_y * 0.1;
	}
	else
	{
		if (d->map_utils->map[(int)(d->p_y - d->dir_x * 0.1)]
			[(int) d->p_x] != '1')
			d->p_y -= d->dir_x * 0.1;
		if (d->map_utils->map[(int)d->p_y]
			[(int)(d->p_x + d->dir_y * 0.1)] != '1')
			d->p_x += d->dir_y * 0.1;
	}
}

/*Esta função rotaciona o jogador para a esquerda ou para 
a direita, dependendo do valor do argumento dir_flag. 
Se dir_flag for 1, o jogador rotaciona para a direita; 
se for diferente de 1 (por exemplo, -1), o jogador rotaciona 
para a esquerda. Ela usa trigonometria para calcular a nova 
direção do jogador e a direção do plano de projeção, com 
base em um ângulo predefinido (0.10 radianos, aproximadamente 
5.7 graus) e a função cos e sin da biblioteca de matemática.*/
void	rotate_player(t_data *d, int dir_flag)
{
	double	angle;
	double	temp_x;
	double	temp_y;

	angle = 0.10;
	if (dir_flag != 1)
		angle *= -1;
	temp_x = d->dir_x * cos(angle) - d->dir_y * sin(angle);
	temp_y = d->dir_x * sin(angle) + d->dir_y * cos(angle);
	d->dir_x = temp_x;
	d->dir_y = temp_y;
	temp_x = d->plane_x * cos(angle) - d->plane_y * sin(angle);
	temp_y = d->plane_x * sin(angle) + d->plane_y * cos(angle);
	d->plane_x = temp_x;
	d->plane_y = temp_y;
}
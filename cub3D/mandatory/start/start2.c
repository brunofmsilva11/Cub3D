/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:15:09 by bruno             #+#    #+#             */
/*   Updated: 2024/05/20 17:15:33 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*Claro, a função get_texture_val é responsável por determinar qual textura será
aplicada à parede atingida pelo raio, com base no lado da parede e na direção do 
raio. Vamos analisar o que cada parte da função faz:

if (d->side == 1): Verifica se o lado atingido da parede é ao longo do eixo y 
(lado 1). Isso indica que o raio atingiu uma parede vertical.
	Se o lado atingido for ao longo do eixo y, verifica se o raio está indo 
	para cima ou para baixo (d->raydir_y < 0). Se estiver indo para cima, 
	define d->aux como a textura correspondente ao sul (d->s_img), que 
	geralmente é a parte inferior da parede. Caso contrário, define d->aux 
	como a textura correspondente ao norte (d->n_img), que geralmente é a 
	parte superior da parede.

else: Se o lado atingido da parede não for ao longo do eixo y, significa que 
é ao longo do eixo x (lado 0), indicando que o raio atingiu uma 
parede horizontal.
	Se o lado atingido for ao longo do eixo x, verifica se o raio está indo 
	para a esquerda ou para a direita (d->raydir_x < 0). Se estiver indo para 
	a esquerda, define d->aux como a textura correspondente ao leste (d->e_img). 
	Caso contrário, define d->aux como a textura correspondente ao oeste (d->w_img).

Essa função é importante para aplicar a textura correta à parede atingida pelo raio, 
garantindo que a renderização da cena seja visualmente correta e realista, de acordo 
com a direção e o lado da parede.*/
void	get_texture_val(t_data *d)
{
	if (d->side == 1)
	{
		if (d->raydir_y < 0)
			d->aux = d->s_img;
		else
			d->aux = d->n_img;
	}
	else
	{
		if (d->raydir_x < 0)
			d->aux = d->e_img;
		else
			d->aux = d->w_img;
	}
}

/*Claro, a função ray_values é responsável por calcular vários valores relacionados 
à renderização do raio e da parede atingida. Vamos analisar o que cada parte da 
função faz:

    if (d->side == 0): Verifica se o lado atingido da parede é ao longo do 
	eixo x (lado 0) ou y (lado 1).
        Se o lado atingido for ao longo do eixo x, calcula a distância perpendicular 
		da parede até a câmera como d->side_dist_x - d->delta_dist_x.
        Se o lado atingido for ao longo do eixo y, calcula a distância perpendicular 
		da parede até a câmera como d->side_dist_y - d->delta_dist_y.

    if (d->perp_wall_dist): Verifica se a distância perpendicular da parede até a 
	câmera é diferente de zero. Isso é feito para evitar divisão por zero.
        Se a distância perpendicular for diferente de zero, calcula a altura da 
		linha que será desenhada na tela com base nessa distância. Quanto mais 
		distante a parede estiver, menor será a linha desenhada na tela.
        Se a distância perpendicular for zero (o que pode acontecer se o raio 
		atingir uma parede diretamente de frente), define a altura da linha como a 
		altura total da tela.

    d->draw_start = -d->line_height / 2 + HEIGHT / 2;: Calcula a coordenada y de 
	onde começar a desenhar a linha da parede na tela. Isso é feito ajustando o 
	centro da linha (HEIGHT / 2) pela metade da altura da linha (d->line_height / 2).
        Se d->draw_start for menor que zero, ajusta-o para zero, garantindo que o 
		desenho da linha comece do topo da tela.

    d->draw_end = d->line_height / 2 + HEIGHT / 2;: Calcula a coordenada y onde 
	terminar de desenhar a linha da parede na tela. Isso é feito ajustando o centro 
	da linha (HEIGHT / 2) pela metade da altura da linha (d->line_height / 2).
        Se d->draw_end for maior ou igual à altura da tela, ajusta-o para a última 
		coordenada y válida na tela.

Essa função é crucial para o processo de renderização do raio e da parede atingida, 
determinando os valores necessários para desenhar corretamente a parede na tela com 
a altura e posição apropriadas.*/
void	ray_values(t_data *d)
{
	if (d->side == 0)
		d->perp_wall_dist = (d->side_dist_x - d->delta_dist_x);
	else
		d->perp_wall_dist = (d->side_dist_y - d->delta_dist_y);
	if (d->perp_wall_dist)
		d->line_height = (int)(HEIGHT / d->perp_wall_dist);
	else
		d->line_height = HEIGHT;
	d->draw_start = -d->line_height / 2 + HEIGHT / 2;
	if (d->draw_start < 0)
		d->draw_start = 0;
	d->draw_end = d->line_height / 2 + HEIGHT / 2;
	if (d->draw_end >= HEIGHT)
		d->draw_end = HEIGHT - 1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:21:10 by bmota-si          #+#    #+#             */
/*   Updated: 2024/05/20 17:14:59 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*Claro, a função get_hit é responsável por determinar o ponto de interseção 
do raio com a parede mais próxima. Vamos examinar o que cada parte da função faz:

while (!d->hit): Este loop executa até que uma parede seja atingida 
(d->hit seja verdadeiro). Enquanto isso, ele continua atualizando a 
posição do raio e 
verificando se ele atingiu uma parede.

if (d->side_dist_x < d->side_dist_y): Verifica se a distância até o 
próximo lado x do bloco é menor do que a distância até o próximo lado y. 
Isso determina se o próximo passo do raio será ao longo do eixo x*/
void	get_hit(t_data *d)
{
	while (!d->hit)
	{
		if (d->side_dist_x < d->side_dist_y)
		{
			d->side_dist_x += d->delta_dist_x;
			d->mapx += d->stepx;
			d->side = 0;
		}
		else
		{
			d->side_dist_y += d->delta_dist_y;
			d->mapy += d->stepy;
			d->side = 1;
		}
		if (d->map_utils->map[d->mapy][d->mapx] == '1')
			d->hit = 1;
	}
}

/*    if (d->raydir_x < 0): Verifica se o componente x da direção do raio 
é negativo. Isso indica que o raio está indo para a esquerda no plano 
da tela.

        d->stepx = -1;: Se o raio estiver indo para a esquerda, define 
		d->stepx como -1, indicando que o próximo bloco ao longo do eixo 
		x será para a esquerda.

        d->side_dist_x = (d->p_x - d->mapx) * d->delta_dist_x;: Calcula 
		a distância do raio até o próximo lado x do bloco à esquerda. 
		Isso é feito multiplicando a 
		diferença entre a posição x atual da câmera (d->p_x) e a 
		coordenada x do bloco atual (d->mapx) pela distância do 
		raio entre os lados x dos 
		blocos (d->delta_dist_x).

    else: Se o componente x da direção do raio não for negativo, então o 
	raio está indo para a direita no plano da tela.

        d->stepx = 1;: Se o raio estiver indo para a direita, define d->stepx 
		como 1, indicando que o próximo bloco ao longo do eixo x será 
		para a direita.

        d->side_dist_x = (d->mapx + 1.0 - d->p_x) * d->delta_dist_x;: 
		Calcula a distância do raio até o próximo lado x do bloco à direita. 
		Isso é feito multiplicando a diferença entre a coordenada x do próximo 
		bloco à direita (d->mapx + 1.0) e a posição x atual da câmera (d->p_x) 
		pela distância do raio entre os lados x dos blocos (d->delta_dist_x).

    O procedimento para determinar o lado do bloco ao longo do 
	eixo y (d->raydir_y) é semelhante ao descrito acima, mas aplicado 
	ao eixo y e usando d->stepy e 
	d->side_dist_y para armazenar as informações correspondentes.

Essa função é essencial para o algoritmo de raycasting, pois determina o 
lado do próximo bloco que o raio irá atingir ao atravessar a cena. Isso é 
necessário para calcular corretamente a distância do raio até o próximo 
ponto de interseção com uma parede.
Esta funcao verifica para que lado a direcao esta a ir para definir em 
que lado da parede esta a bater.*/
void	check_side(t_data *d)
{
	if (d->raydir_x < 0)
	{
		d->stepx = -1;
		d->side_dist_x = (d->p_x - d->mapx) * d->delta_dist_x;
	}
	else
	{
		d->stepx = 1;
		d->side_dist_x = (d->mapx + 1.0 - d->p_x) * d->delta_dist_x;
	}
	if (d->raydir_y < 0)
	{
		d->stepy = -1;
		d->side_dist_y = (d->p_y - d->mapy) * d->delta_dist_y;
	}
	else
	{
		d->stepy = 1;
		d->side_dist_y = (d->mapy + 1.0 - d->p_y) * d->delta_dist_y;
	}
}

/*Esta função ray_calc é responsável por calcular os valores necessários 
para lançar um raio na cena. Aqui está uma explicação detalhada do que 
cada linha faz:

    d->camera_x = 2 * d->i / (double)WIDTH - 1;: Calcula a coordenada x da 
	câmera no espaço de projeção. Isso é feito para normalizar as coordenadas 
	da câmera entre -1 
	e 1, onde -1 representa a extremidade esquerda da tela e 1 representa 
	a extremidade direita.

    d->raydir_x = d->dir_x + d->plane_x * d->camera_x;: Calcula o 
	componente x da direção do raio lançado. Isso envolve a direção 
	da câmera (d->dir_x) e o plano da 
	câmera (d->plane_x), ajustados pela coordenada x da câmera 
	no espaço de projeção.

    d->raydir_y = d->dir_y + d->plane_y * d->camera_x;: Calcula o 
	componente y da direção do raio lançado. É semelhante ao cálculo 
	anterior, mas para o eixo y.

    d->mapx = (int)d->p_x;: Calcula a coordenada x do bloco no qual 
	o raio atinge primeiro. Isso é feito convertendo a coordenada x 
	atual da câmera (d->p_x) para um 
	número inteiro.

    d->mapy = (int)d->p_y;: Calcula a coordenada y do bloco no qual 
	o raio atinge primeiro. Semelhante ao cálculo anterior, mas para o eixo y.

    if (d->raydir_x == 0) d->delta_dist_x = 1e30;: Calcula a distância 
	do raio entre cada lado x dos blocos. Se d->raydir_x for zero, 
	define d->delta_dist_x para um 
	valor grande para evitar divisão por zero.

    else d->delta_dist_x = fabs(1 / d->raydir_x);: Calcula d->delta_dist_x 
	como o inverso do componente x da direção do raio. 
	Isso é feito para calcular a distância 
	do raio entre os blocos ao longo do eixo x.

    if (d->raydir_y == 0) d->delta_dist_y = 1e30;: Calcula a distância 
	do raio entre cada lado y dos blocos. Se d->raydir_y for zero, 
	define d->delta_dist_y para um 
	valor grande para evitar divisão por zero.

    else d->delta_dist_y = fabs(1 / d->raydir_y);: Calcula d->delta_dist_y 
	como o inverso do componente y da direção do raio. Isso é feito para 
	calcular a distância 
	do raio entre os blocos ao longo do eixo y.

    d->hit = 0;: Define d->hit como zero, indicando que o raio ainda 
	não atingiu nada.*/
void	ray_calc(t_data *d)
{
	d->camera_x = 2 * d->i / (double)WIDTH - 1;
	d->raydir_x = d->dir_x + d->plane_x * d->camera_x;
	d->raydir_y = d->dir_y + d->plane_y * d->camera_x;
	d->mapx = (int)d->p_x;
	d->mapy = (int)d->p_y;
	if (d->raydir_x == 0)
		d->delta_dist_x = 1e30;
	else
		d->delta_dist_x = fabs(1 / d->raydir_x);//obtem a distancia ao bloco encontrado no eixo dos x.
	if (d->raydir_y == 0)
		d->delta_dist_y = 1e30;
	else
		d->delta_dist_y = fabs(1 / d->raydir_y);//obtem a distancia ao bloco encontrado no eixo dos y.
	d->hit = 0;
}

void	draw_raycast(t_data *d)
{
	put_color_on_window(d);
	d->i = 0;
	while (d->i < WIDTH)
	{
		ray_calc(d);//verifica o tamanho do raio.
		check_side(d);//verifica lado da parede que esta a bater.
		get_hit(d);
		ray_values(d);
		get_texture_val(d);
		ft_draw(d, d->i);
		d->i++;
	}
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img->img, 0, 0);
}

void	ft_start(t_data *d)
{
	d->mlx_ptr = mlx_init();
	if (d->mlx_ptr == NULL)
		return ;
	init_struct_imgs(d);
	ft_init_stack3(d);
	get_imgs_xpm(d);
	d->win_ptr = mlx_new_window(d->mlx_ptr, WIDTH, HEIGHT, "CUB3D");
	direction(d);
	draw_raycast(d);
	mlx_hook(d->win_ptr, KeyPress, KeyPressMask, handle_input, d);
	mlx_hook(d->win_ptr, KeyRelease, KeyReleaseMask, release_key, d);
	mlx_hook(d->win_ptr, DestroyNotify, ButtonPressMask, ft_exit_x, d);
	mlx_loop_hook(d->mlx_ptr, game_loop, d);
	mlx_loop(d->mlx_ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:21:10 by bmota-si          #+#    #+#             */
/*   Updated: 2024/05/15 15:44:41 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*Claro, a função get_texture_val é responsável por determinar qual textura será aplicada à parede atingida pelo raio, com base no lado da parede e na direção do raio. Vamos analisar o que cada parte da função faz:

    if (d->side == 1): Verifica se o lado atingido da parede é ao longo do eixo y (lado 1). Isso indica que o raio atingiu uma parede vertical.
        Se o lado atingido for ao longo do eixo y, verifica se o raio está indo para cima ou para baixo (d->raydir_y < 0). Se estiver indo para cima, define d->aux como a textura correspondente ao sul (d->s_img), que geralmente é a parte inferior da parede. Caso contrário, define d->aux como a textura correspondente ao norte (d->n_img), que geralmente é a parte superior da parede.

    else: Se o lado atingido da parede não for ao longo do eixo y, significa que é ao longo do eixo x (lado 0), indicando que o raio atingiu uma parede horizontal.
        Se o lado atingido for ao longo do eixo x, verifica se o raio está indo para a esquerda ou para a direita (d->raydir_x < 0). Se estiver indo para a esquerda, define d->aux como a textura correspondente ao leste (d->e_img). Caso contrário, define d->aux como a textura correspondente ao oeste (d->w_img).

Essa função é importante para aplicar a textura correta à parede atingida pelo raio, garantindo que a renderização da cena seja visualmente correta e realista, de acordo com a direção e o lado da parede.*/
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

/*Claro, a função ray_values é responsável por calcular vários valores relacionados à renderização do raio e da parede atingida. Vamos analisar o que cada parte da função faz:

    if (d->side == 0): Verifica se o lado atingido da parede é ao longo do eixo x (lado 0) ou y (lado 1).
        Se o lado atingido for ao longo do eixo x, calcula a distância perpendicular da parede até a câmera como d->side_dist_x - d->delta_dist_x.
        Se o lado atingido for ao longo do eixo y, calcula a distância perpendicular da parede até a câmera como d->side_dist_y - d->delta_dist_y.

    if (d->perp_wall_dist): Verifica se a distância perpendicular da parede até a câmera é diferente de zero. Isso é feito para evitar divisão por zero.
        Se a distância perpendicular for diferente de zero, calcula a altura da linha que será desenhada na tela com base nessa distância. Quanto mais distante a parede estiver, menor será a linha desenhada na tela.
        Se a distância perpendicular for zero (o que pode acontecer se o raio atingir uma parede diretamente de frente), define a altura da linha como a altura total da tela.

    d->draw_start = -d->line_height / 2 + HEIGHT / 2;: Calcula a coordenada y de onde começar a desenhar a linha da parede na tela. Isso é feito ajustando o centro da linha (HEIGHT / 2) pela metade da altura da linha (d->line_height / 2).
        Se d->draw_start for menor que zero, ajusta-o para zero, garantindo que o desenho da linha comece do topo da tela.

    d->draw_end = d->line_height / 2 + HEIGHT / 2;: Calcula a coordenada y onde terminar de desenhar a linha da parede na tela. Isso é feito ajustando o centro da linha (HEIGHT / 2) pela metade da altura da linha (d->line_height / 2).
        Se d->draw_end for maior ou igual à altura da tela, ajusta-o para a última coordenada y válida na tela.

Essa função é crucial para o processo de renderização do raio e da parede atingida, determinando os valores necessários para desenhar corretamente a parede na tela com a altura e posição apropriadas.*/
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

/*Claro, a função get_hit é responsável por determinar o ponto de interseção do raio com a parede mais próxima. Vamos examinar o que cada parte da função faz:

    while (!d->hit): Este loop executa até que uma parede seja atingida (d->hit seja verdadeiro). Enquanto isso, ele continua atualizando a posição do raio e 
	verificando se ele atingiu uma parede.

    if (d->side_dist_x < d->side_dist_y): Verifica se a distância até o próximo lado x do bloco é menor do que a distância até o próximo lado y. 
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

/*    if (d->raydir_x < 0): Verifica se o componente x da direção do raio é negativo. Isso indica que o raio está indo para a esquerda no plano da tela.

        d->stepx = -1;: Se o raio estiver indo para a esquerda, define d->stepx como -1, indicando que o próximo bloco ao longo do eixo x será para a esquerda.

        d->side_dist_x = (d->p_x - d->mapx) * d->delta_dist_x;: Calcula a distância do raio até o próximo lado x do bloco à esquerda. Isso é feito multiplicando a 
		diferença entre a posição x atual da câmera (d->p_x) e a coordenada x do bloco atual (d->mapx) pela distância do raio entre os lados x dos 
		blocos (d->delta_dist_x).

    else: Se o componente x da direção do raio não for negativo, então o raio está indo para a direita no plano da tela.

        d->stepx = 1;: Se o raio estiver indo para a direita, define d->stepx como 1, indicando que o próximo bloco ao longo do eixo x será para a direita.

        d->side_dist_x = (d->mapx + 1.0 - d->p_x) * d->delta_dist_x;: Calcula a distância do raio até o próximo lado x do bloco à direita. Isso é feito multiplicando a diferença entre a coordenada x do próximo bloco à direita (d->mapx + 1.0) e a posição x atual da câmera (d->p_x) pela distância do raio entre os lados x dos blocos (d->delta_dist_x).

    O procedimento para determinar o lado do bloco ao longo do eixo y (d->raydir_y) é semelhante ao descrito acima, mas aplicado ao eixo y e usando d->stepy e 
	d->side_dist_y para armazenar as informações correspondentes.

Essa função é essencial para o algoritmo de raycasting, pois determina o lado do próximo bloco que o raio irá atingir ao atravessar a cena. Isso é necessário para calcular corretamente a distância do raio até o próximo ponto de interseção com uma parede.*/
//Esta funcao verifica para que lado a direcao esta a ir para definir em que lado da parede esta a bater.
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

/*Esta função ray_calc é responsável por calcular os valores necessários para lançar um raio na cena. Aqui está uma explicação detalhada do que cada linha faz:

    d->camera_x = 2 * d->i / (double)WIDTH - 1;: Calcula a coordenada x da câmera no espaço de projeção. Isso é feito para normalizar as coordenadas da câmera entre -1 
	e 1, onde -1 representa a extremidade esquerda da tela e 1 representa a extremidade direita.

    d->raydir_x = d->dir_x + d->plane_x * d->camera_x;: Calcula o componente x da direção do raio lançado. Isso envolve a direção da câmera (d->dir_x) e o plano da 
	câmera (d->plane_x), ajustados pela coordenada x da câmera no espaço de projeção.

    d->raydir_y = d->dir_y + d->plane_y * d->camera_x;: Calcula o componente y da direção do raio lançado. É semelhante ao cálculo anterior, mas para o eixo y.

    d->mapx = (int)d->p_x;: Calcula a coordenada x do bloco no qual o raio atinge primeiro. Isso é feito convertendo a coordenada x atual da câmera (d->p_x) para um 
	número inteiro.

    d->mapy = (int)d->p_y;: Calcula a coordenada y do bloco no qual o raio atinge primeiro. Semelhante ao cálculo anterior, mas para o eixo y.

    if (d->raydir_x == 0) d->delta_dist_x = 1e30;: Calcula a distância do raio entre cada lado x dos blocos. Se d->raydir_x for zero, define d->delta_dist_x para um 
	valor grande para evitar divisão por zero.

    else d->delta_dist_x = fabs(1 / d->raydir_x);: Calcula d->delta_dist_x como o inverso do componente x da direção do raio. Isso é feito para calcular a distância 
	do raio entre os blocos ao longo do eixo x.

    if (d->raydir_y == 0) d->delta_dist_y = 1e30;: Calcula a distância do raio entre cada lado y dos blocos. Se d->raydir_y for zero, define d->delta_dist_y para um 
	valor grande para evitar divisão por zero.

    else d->delta_dist_y = fabs(1 / d->raydir_y);: Calcula d->delta_dist_y como o inverso do componente y da direção do raio. Isso é feito para calcular a distância 
	do raio entre os blocos ao longo do eixo y.

    d->hit = 0;: Define d->hit como zero, indicando que o raio ainda não atingiu nada.*/
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
	//mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img->img, 0, 0);
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
	mlx_hook(d->win_ptr, KeyRelease, KeyReleaseMask, release_key, d);
	mlx_hook(d->win_ptr, DestroyNotify, ButtonPressMask, ft_exit_x, d);//Quando X e carregado fecha programa e da frees!
	mlx_loop_hook(d->mlx_ptr, game_loop, d);
	mlx_loop(d->mlx_ptr);
}

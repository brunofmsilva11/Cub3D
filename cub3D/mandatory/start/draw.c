/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:18:27 by bmota-si          #+#    #+#             */
/*   Updated: 2024/05/15 15:45:00 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*Vamos começar com a função ft_draw. Esta função é responsável por desenhar a coluna da parede na tela, aplicando corretamente a textura à superfície da parede. Aqui está uma explicação linha por linha:

    get_wall_x(d);: Calcula a coordenada x na textura da parede onde o raio atingiu. Isso é feito pela função get_wall_x, que calcula d->wall_x.

    d->tex_x = (int)(d->wall_x * (double)TEX_WIDTH);: Calcula a coordenada x na textura real, levando em conta a largura da textura (TEX_WIDTH).

    d->tex_x = TEX_WIDTH - d->tex_x - 1;: Ajusta a coordenada x da textura para garantir que a textura seja desenhada corretamente e não invertida.

    d->text_step = 1.0 * TEX_WIDTH / d->line_height;: Calcula o tamanho do passo na textura para garantir que ela seja desenhada corretamente em relação à altura da linha.

    d->text_pos = (d->draw_start - HEIGHT / 2 + d->line_height / 2) * d->text_step;: Calcula a posição inicial na textura para começar a desenhar, ajustando com base na altura da linha e na posição de desenho na tela.

    y = d->draw_start;: Inicializa o contador y com a posição de início de desenho na tela.

    while (y < d->draw_end): Inicia um loop que desenha a textura da parede de cima para baixo, dentro da altura da linha.

    d->tex_y = (int)d->text_pos & (TEX_HEIGHT - 1);: Calcula a coordenada y na textura, levando em conta a altura da textura (TEX_HEIGHT).

    d->text_pos += d->text_step;: Atualiza a posição na textura para o próximo pixel na coluna da parede.

    if (i >= 0 && y >= 0 && d->tex_x >= 0 && d->tex_y >= 0): Verifica se as coordenadas estão dentro dos limites da tela e da textura.

    color = ft_get_pixel(d, d->tex_x, d->tex_y);: Obtém a cor do pixel correspondente na textura.

    my_mlx_pixel_put(d, i, y, color);: Desenha o pixel na tela.*/
void	ft_draw(t_data *d, int i)
{
	int	color;
	int	y;

	get_wall_x(d);
	d->tex_x = (int)(d->wall_x * (double)TEX_WIDTH);
	d->tex_x = TEX_WIDTH - d->tex_x - 1;
	d->text_step = 1.0 * TEX_WIDTH / d->line_height;
	d->text_pos = (d->draw_start - HEIGHT / 2
			+ d->line_height / 2) * d->text_step;
	y = d->draw_start;
	while (y < d->draw_end)
	{
		d->tex_y = (int)d->text_pos & (TEX_HEIGHT - 1);
		d->text_pos += d->text_step;
		if (i >= 0 && y >= 0 && d->tex_x >= 0 && d->tex_y >= 0)
		{
			color = ft_get_pixel(d, d->tex_x, d->tex_y);
			//mlx_pixel_put(d->mlx_ptr, d->win_ptr, i, y, color);
			my_mlx_pixel_put(d, i, y, color);
		}
		y++;
	}
}

/*    if (d->side == 0): Verifica se o lado atingido da parede é ao longo do eixo x (lado 0).
        Calcula a coordenada x na textura da parede onde o raio atingiu, levando em conta a distância perpendicular da parede até a câmera e a direção do raio ao longo do eixo y.

    if (d->side == 1): Verifica se o lado atingido da parede é ao longo do eixo y (lado 1).
        Calcula a coordenada x na textura da parede onde o raio atingiu, levando em conta a distância perpendicular da parede até a câmera e a direção do raio ao longo do eixo x.*/
void	get_wall_x(t_data *d)
{
	if (d->side == 0)
	{
		d->wall_x = d->p_y + d->perp_wall_dist * d->raydir_y;
		d->wall_x -= floor(d->wall_x);
	}
	if (d->side == 1)
	{
		d->wall_x = d->p_x + d->perp_wall_dist * d->raydir_x;
		d->wall_x -= floor(d->wall_x);
	}
}

/*a função ft_get_pixel é responsável por obter a cor do pixel na textura, dados os índices x e y. Ela acessa diretamente a matriz de pixels da textura usando a informação de endereço (addr), comprimento da linha (line_length), e bytes por pixel (bpp).*/
int	ft_get_pixel(t_data *d, int x, int y)
{
	return (*(unsigned int *)((d->aux->addr
			+ (y * d->aux->line_length) + (x * d->aux->bpp / 8))));
}

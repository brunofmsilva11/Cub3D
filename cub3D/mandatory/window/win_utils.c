/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:06:50 by bmota-si          #+#    #+#             */
/*   Updated: 2024/05/07 18:40:55 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
/*    Declarar dst:
        char *dst;: Declara um ponteiro dst do tipo char. Este ponteiro armazenará posteriormente o endereço de memória do pixel alvo.

    Calcular Endereço do Pixel:
        dst = data->img->addr + (y * data->img->line_length + x * (data->img->bpp / 8)):
            data->img->addr: Acessa um membro chamado addr dentro do membro img da estrutura data. Este membro addr provavelmente guarda o endereço base dos dados da imagem na memória.
            O cálculo y * data->img->line_length + x * (data->img->bpp / 8) computa o deslocamento em bytes a partir do endereço base da imagem para alcançar o pixel desejado.
                y * data->img->line_length: Considera a coordenada y multiplicando-a pelo line_length (comprimento da linha), que provavelmente representa o número de bytes em uma única linha da imagem.
                x * (data->img->bpp / 8): Considera a coordenada x multiplicando-a pelo bpp (bytes por pixel) dividido por 8 (número de bits por byte). Isso calcula o deslocamento em bytes dentro de uma linha para alcançar os dados de cor do pixel específico.
            Ao adicionar este deslocamento ao endereço base, dst agora aponta para o local da memória onde o valor da cor do pixel em (x, y) está armazenado.

    Definir Cor do Pixel:
        *(unsigned int *)dst = color;:
            *(unsigned int *)dst: Realiza uma operação de desreferenciamento em dst, tratando-o como um ponteiro para um unsigned int (4 bytes). Essencialmente, converte o local de memória apontado por dst em um valor inteiro.
            = color: Atribui o valor color fornecido (que deve ser um inteiro representando a cor desejada do pixel no formato da biblioteca) ao local da memória apontado por dst.

Resumindo, esta função define de forma eficiente a cor de um pixel em um local específico dentro de uma estrutura de dados de imagem.*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img->addr + (y * data->img->line_length
			+ x * (data->img->bpp / 8));
	*(unsigned int *)dst = color;
}

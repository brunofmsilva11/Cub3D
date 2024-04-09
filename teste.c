/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:06:28 by bmota-si          #+#    #+#             */
/*   Updated: 2024/04/09 15:12:33 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int main(void)
{
    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;
    int img_width;
    int img_height;

    mlx_ptr = mlx_init(); // Inicializa a MinilibX
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Exemplo com Imagem"); // Cria uma nova janela

    // Carrega a imagem (ajuste o caminho para o local da sua imagem XPM)
    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "caminho/para/sua/imagem.xpm", &img_width, &img_height);

    // Verifica se a imagem foi carregada corretamente
    if (img_ptr != NULL)
    {
        // Caso a imagem esteja carregada corretamente, exibe-a na janela
        mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
    }
    else
    {
        // Tratamento de erro, caso a imagem não tenha sido carregada
        // Pode imprimir um erro e/ou sair do programa
    }

    mlx_loop(mlx_ptr); // Entra no loop de eventos do MinilibX
    return (0);
}

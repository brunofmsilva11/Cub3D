/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:57:34 by bmota-si          #+#    #+#             */
/*   Updated: 2024/05/08 15:27:34 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

//Verifica se existem os 6 elementos para criar o mapa, o caminho das respetivas imagens e as cores!
void	six_args(t_data *d, char *file_name)
{
	char	*line;

	d->fd = open(file_name, O_RDONLY);
	while (!d->map_utils->no || !d->map_utils->f_color || !d->map_utils->we
		|| !d->map_utils->ea || !d->map_utils->so || !d->map_utils->c_color)
	{
		line = get_next_line(d->fd);
		if (!line)
			error_dup_elem(d, line, 1);
		if (ft_strchr(" 1", line[0]))
			error_dup_elem(d, line, 1);
		if (!check_direc(d, line) && line[0] != '\n')//Verifica se a string e valida ou se e '\n'(se for e valido)!
			error_dup_elem(d, line, 1);
		free(line);
		d->map_utils->skip_count++;
	}
	printf("%i linhas!\n", d->map_utils->skip_count);
	ft_no_leak(d, line);//Verifica o resto do mapa.
	ft_check_textures(d);
	map_validation_test(d, file_name);//verifica o mapa depois de verificar os primeiros 6 elementos!
	//map_to_file(d, file_name);
}

void	check_null_file(t_data *d, char *file_name)
{
	char	*line;

	d->fd = open(file_name, O_RDONLY);
	line = get_next_line(d->fd);
	if (!line)
	{
		ft_free_data(d);
		finish_error("Error: no content on file\n", 2);
	}
	ft_no_leak2(d, line);
	free(line);
}

void	ft_check_map_file(t_data *d, char *file_name)
{
	int	i;

	//Verifica se tem o ficheiro que foi dado como av[1] tem '.'!
	i = ft_strlen(file_name) - 1;
	while (file_name[i] != '.')
	{
		if (!file_name[i])
			file_name_error(d);//Se nao tiver '.' da frees a estrutura data e print de invalid file!
		i--;
	}
	if (!string_comp((file_name + i), ".cub"))//Compara o file_name desde o '.' com '.cub'!
		file_name_error(d);
	d->fd = open(file_name, O_RDONLY);
	if (d->fd < 0)
	{
		free(d->map_utils);
		free(d);
		finish_error("Error\nInvalid FD\n", 2);
	}
	close(d->fd);
	d->fd = 0;
	check_null_file(d, file_name);
	six_args(d, file_name);
}

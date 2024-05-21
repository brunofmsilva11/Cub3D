/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:21:13 by bruno             #+#    #+#             */
/*   Updated: 2024/05/20 15:25:18 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_no_leak3(t_data *d, char *line)
{
	int	i;

	i = 0;
	while (1)
	{
		if (line)
		{
			while (line)
			{
				free(line);
				line = get_next_line(d->fd);
			}
			return (0);
		}
		else
			break ;
	}
	close(d->fd);
	if (i == 0)
		return (1);
	return (0);
}

void	free_imgs(t_data *d)
{
	if (d->img)
		free(d->img);
	if (d->n_img)
		free(d->n_img);
	if (d->s_img)
		free(d->s_img);
	if (d->w_img)
		free(d->w_img);
	if (d->e_img)
		free(d->e_img);
}

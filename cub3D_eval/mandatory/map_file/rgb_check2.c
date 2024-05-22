/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:00:32 by bmota-si          #+#    #+#             */
/*   Updated: 2024/05/20 16:26:04 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	*remove_tabs(char *str)
{
	int		i;
	int		j;
	char	*dup;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\t' || str[i] == ' ')
			j++;
		i++;
	}
	dup = ft_strdup(str + j);
	free(str);
	return (dup);
}

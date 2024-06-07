/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:33:00 by bmota-si          #+#    #+#             */
/*   Updated: 2024/06/05 14:37:43 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnumber(char *string)
{
	int	return_value;
	int	i;

	return_value = 1;
	i = 0;
	if (string[0] == '+' || string[0] == '-')
		i++;
	if (string[0] == '-')
		return_value = -1;
	while (string[i])
	{
		if (!ft_isdigit((int)string[i]))
			return (0);
		i++;
	}
	return (return_value);
}

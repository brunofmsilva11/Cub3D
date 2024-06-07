/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:23:05 by bmota-si          #+#    #+#             */
/*   Updated: 2024/06/05 14:37:43 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp_input(const char *input, const char *limiter)
{
	unsigned int	i;
	unsigned int	result;
	char			*newlimiter;

	newlimiter = ft_strjoin(limiter, "\n");
	if (!newlimiter)
		return (0);
	i = 0;
	while (input[i] && newlimiter[i] && (input[i] == newlimiter[i]))
		i++;
	result = (unsigned char)input[i] - (unsigned char)newlimiter[i];
	free (newlimiter);
	return (result);
}

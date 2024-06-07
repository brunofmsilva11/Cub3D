/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:37:39 by bmota-si          #+#    #+#             */
/*   Updated: 2024/06/05 14:37:43 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_string(char *string)
{
	char	*substr;
	int		count;

	if (!string)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	substr = ft_substr(string, 0, ft_strlen(string));
	if (!substr)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(substr, 1);
	count = ft_strlen(substr);
	free(substr);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tolower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:57:45 by bmota-si          #+#    #+#             */
/*   Updated: 2024/06/05 14:37:43 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_str_tolower(char *str)
{
	char	*lower_str;
	int		i;

	if (!str)
		return (NULL);
	lower_str = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!lower_str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			lower_str[i] = ft_tolower(str[i]);
		else
			lower_str[i] = str[i];
		i++;
	}
	lower_str[i] = '\0';
	return (lower_str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 13:34:55 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/18 17:04:19 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* LIBRARY: <string.h>
** SYNOPSIS: save a copy of a string (with malloc)
** DESCRIPTION: The strdup() function allocates sufficient
** memory for a copy of the string s1, does the copy,
** and returns a pointer to it.  The pointer may
** subsequently be used as an argument to the function free(3).
*/

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*cpy;
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	cpy = (char *)malloc(sizeof(char) * i + 1);
	if (!cpy)
		return (NULL);
	i = 0;
	while (*src)
		cpy[i++] = *src++;
	cpy[i] = '\0';
	return (cpy);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:09:41 by bmota-si          #+#    #+#             */
/*   Updated: 2024/06/05 14:37:43 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* LIBRARY: <string.h>
** DESCRIPTION: The memset function fills the firsts "n" 
** bytes of the string "s" for "c".
*/

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_cast;

	s_cast = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		s_cast[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

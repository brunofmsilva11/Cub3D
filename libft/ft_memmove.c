/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:36:17 by bmota-si          #+#    #+#             */
/*   Updated: 2024/06/05 14:37:43 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	LIBRARY: <string.h>
**	DESCRIPTION: The memmove() function copies n 
**	bytes from string src to string dest. The two strings may overlap;
**	the copy is always done in a non-destructive manner.
**	The difference between memmove and memcpy it's that memmove uses a buffer*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (((unsigned char *)dest) == ((unsigned char *)src))
		return (dest);
	if (dest > src)
	{
		while (n > 0)
		{
			((unsigned char *)dest)[n - 1] = ((unsigned char *)src)[n - 1];
			n--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:57:57 by bmota-si          #+#    #+#             */
/*   Updated: 2024/06/05 14:37:43 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_tabdup(char **tab)
{
	char	**newtab;
	char	*temp;
	int		i;

	i = 0;
	if (tab == NULL)
		return (NULL);
	while (tab[i] != NULL)
		i++;
	newtab = (char **)malloc(sizeof(char *) * (i + 1));
	if (newtab == NULL)
		return (NULL);
	i = 0;
	while (tab[i] != NULL)
	{
		temp = ft_strdup(tab[i]);
		if (temp == NULL)
		{
			ft_free_tabs((void **)newtab);
			return (NULL);
		}
		newtab[i++] = temp;
	}
	newtab[i] = NULL;
	return (newtab);
}

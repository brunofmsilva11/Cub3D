/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uns_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:52:31 by bmota-si          #+#    #+#             */
/*   Updated: 2024/06/05 14:39:27 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa(unsigned int n)
{
	char					*result;
	int						digit_length;
	long					n_copy;

	digit_length = 0;
	n_copy = n;
	if (n == 0)
		digit_length++;
	while (n_copy != 0)
	{
		n_copy = n_copy / 10;
		digit_length++;
	}
	result = (char *)malloc(sizeof(char) * digit_length + 1);
	if (!result)
		return (NULL);
	result[digit_length] = '\0';
	while (digit_length)
	{
		result[digit_length - 1] = n % 10 + '0';
		n /= 10;
		digit_length--;
	}
	return (result);
}

int	ft_printf_unsint_fd(unsigned int unsigned_n, int fd)
{
	char	*str;
	int		count;

	str = ft_utoa(unsigned_n);
	if (!str)
		return (0);
	ft_putstr_fd(str, fd);
	count = ft_strlen(str);
	free(str);
	return (count);
}

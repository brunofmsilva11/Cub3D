/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 18:29:35 by bmota-si          #+#    #+#             */
/*   Updated: 2024/06/05 14:37:43 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  Allocate (with malloc(3)) and returns a “fresh” string ending 
**  with ’\0’ representing the integer n given as argument.
**  Negative numbers must be supported. If the allocation fails,
**  the function returns NULL.
*/

#include "libft.h"

static int	digit_length(int n)
{
	int	digit_length;

	digit_length = 0;
	if (n <= 0)
		digit_length++;
	while (n != 0)
	{
		n = n / 10;
		digit_length++;
	}
	return (digit_length);
}

static void	fill_result(int len, int index, int n, char *result)
{
	while (len > index)
	{
		result[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	char		*result;
	int			index;
	int			len;

	index = 0;
	len = digit_length(n);
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	if (n == -2147483648)
	{
		result[0] = '-';
		result[1] = '2';
		n = 147483648;
		index = 2;
	}
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
		index++;
	}
	fill_result(len, index, n, result);
	result[len] = '\0';
	return (result);
}

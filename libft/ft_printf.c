/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:39:15 by bmota-si          #+#    #+#             */
/*   Updated: 2024/06/05 14:38:04 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_arg(char *string, int *i, va_list args)
{
	int		counter;

	(*i)++;
	counter = 0;
	if (string[*i] == '%')
		counter += ft_printf_char_fd('%', 1);
	else if (string[*i] == 'c')
		counter += ft_printf_char_fd(va_arg(args, int), 1);
	else if (string[*i] == 's')
		counter += ft_printf_string_fd(va_arg(args, char *), 1);
	else if (string[*i] == 'd' || string[*i] == 'i')
		counter += ft_printf_int_fd(va_arg(args, int), 1);
	else if (string[*i] == 'u')
		counter += ft_printf_unsint_fd(va_arg(args, unsigned int), 1);
	else if (string[*i] == 'x')
		counter += ft_printf_base_fd(va_arg(args, int), "0123456789abcdef", 1);
	else if (string[*i] == 'X')
		counter += ft_printf_base_fd(va_arg(args, int), "0123456789ABCDEF", 1);
	else if (string[*i] == 'p')
		counter += ft_printf_ptr_fd(va_arg(args, void *), 1);
	return (counter);
}

int	ft_printf(const char *string, ...)
{
	int		counter;
	int		i;
	va_list	args;
	char	*str;

	str = (char *)string;
	counter = 0;
	i = 0;
	va_start(args, string);
	while (str[i])
	{
		if (str[i] == '%')
			counter += check_arg(str, &i, args);
		else
		{
			ft_putchar_fd(str[i], 1);
			counter++;
		}
		i++;
	}
	va_end(args);
	return (counter);
}

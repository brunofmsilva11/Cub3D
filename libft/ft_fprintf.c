/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:39:15 by bmota-si          #+#    #+#             */
/*   Updated: 2024/06/05 14:37:43 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_arg_fd(char *string, int *i, va_list args, int fd)
{
	int		counter;

	(*i)++;
	counter = 0;
	if (string[*i] == '%')
		counter += ft_printf_char_fd('%', fd);
	else if (string[*i] == 'c')
		counter += ft_printf_char_fd(va_arg(args, int), fd);
	else if (string[*i] == 's')
		counter += ft_printf_string_fd(va_arg(args, char *), fd);
	else if (string[*i] == 'd' || string[*i] == 'i')
		counter += ft_printf_int_fd(va_arg(args, int), fd);
	else if (string[*i] == 'u')
		counter += ft_printf_unsint_fd(va_arg(args, unsigned int), fd);
	else if (string[*i] == 'x')
		counter += ft_printf_base_fd(va_arg(args, int), "0123456789abcdef", fd);
	else if (string[*i] == 'X')
		counter += ft_printf_base_fd(va_arg(args, int), "0123456789ABCDEF", fd);
	else if (string[*i] == 'p')
		counter += ft_printf_ptr_fd(va_arg(args, void *), fd);
	return (counter);
}

int	ft_fprintf(int fd, const char *string, ...)
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
			counter += check_arg_fd(str, &i, args, fd);
		else
		{
			ft_putchar_fd(str[i], fd);
			counter++;
		}
		i++;
	}
	va_end(args);
	return (counter);
}
